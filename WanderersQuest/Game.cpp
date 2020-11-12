#include "Game.h"
#include "TexManager.h"

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) // TODO add settings	
{
	count = 0;
	init_game(title, xpos, ypos, width, height, fullscreen);

	init_tex();

	game_dim.h = height;
	game_dim.w = width;

	// TODO int num_players = create game // with settings
	int num_players = 1;

	Dimension dim(20, 20);
	Map::map_dim = dim;
	WQ_map = new Map(renderer);
	
	//std::vector<ArrayPos> starters = WQ_map->generate_map(num_players);

	ui = std::make_unique<UI>(game_dim);

	cards = std::make_shared<Cards>(game_dim);
	players = new PlayerList(num_players, cards);

	std::vector<ArrayPos> starting_loc = WQ_map->generate_map(num_players);
	std::vector<std::shared_ptr<UnitObject>> starter_units = players->assign_starters(starting_loc);
	WQ_map->assign_starters(starter_units);

	WQ_map->grow_around_pivot(players->get_active_player()->get_active_unit()->get_pos(), false);


}
Game::~Game()
{
	delete WQ_map;
	delete players;
}

void Game::init_game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	printf("%s creation started\n", title);
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		printf("SDL initalised successfully.\n");

	}
	else {
		printf("SDL could not initalise. Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
	if (window) {
		printf("Window Created\n");
	}
	else {
		printf("Window Creation Error\n");
		exit(EXIT_FAILURE);
	}
	renderer = SDL_CreateRenderer(window, -1, 0);

	if (renderer) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		printf("Renderer Created\n");
		game_running = true;
	}
	else {
		printf("Renderer Creation Error\n");
		exit(EXIT_FAILURE);
	}

}

void Game::pre_command()
{
	WQ_map->pre_command();
}

void Game::handle_events()
{
	Coor cursor_coor;
	ArrayPos cursor_pos;

	SDL_GetMouseState(&cursor_coor.x, &cursor_coor.y);
	if (not cards->cursor_on(cursor_coor)) {
		cursor_pos = WQ_map->find_cursor_hex(cursor_coor);
		find_path(cursor_pos, false); // TODO add cursor pos based on window // Find path assigns to hex when unit is active
	}
	
	
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			game_running = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
		{
			if (ui->cursor_on(cursor_coor)) next_turn();
			else move_unit(cursor_pos);
			break;
		}
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_g: {
				WQ_map->grow_around_pivot(players->get_active_player()->get_active_unit()->get_pos(), true);
				break; }
			case SDLK_w:	
				WQ_map->move_up(5);
				break;
			case SDLK_a:
				WQ_map->move_left(30);
				break;
			case SDLK_s:
				WQ_map->move_down(20);
				break;
			case SDLK_d:
				WQ_map->move_right(5);
				break;
			case SDLK_c: {
				std::shared_ptr<UnitObject>  unit = players->get_active_player()->create_unit(ArrayPos(5, 2));
				WQ_map->assign_unit(unit);
				break; }
			case SDLK_l:
				next_turn();
				break;
			case SDLK_n: {
				std::shared_ptr<UnitObject>  unit = players->get_active_player()->get_next_unit();
				WQ_map->grow_around_pivot(unit->get_pos(), true);
				break;
			}
			case SDLK_u:
				use_settlement();
				break;
			case SDLK_z:
				WQ_map->zoom_out();
				break;
			case SDLK_p:
				players->get_active_player()->get_active_unit()->print_skills();
			case SDLK_k:
				kill_unit(players->get_active_player(), players->get_active_player()->get_active_unit());
			}
			
		}
	}

	//std::cerr << "after handel\n";
	
}

void Game::update()
{
	//std::cerr << "in update\n";
	WQ_map->update();
	cards->update();
	
	count++;
	//std::cout << count << std::endl;

	//std::cout << "after update\n";
}

void Game::render()
{

	//std::cout << "in render\n";
	SDL_RenderClear(renderer);

	WQ_map->render();
	players->render();
	ui->render();
	
	SDL_RenderPresent(renderer);

	//std::cout << "after render\n";
	
}

void Game::init_tex() // TODO have it for all
{
	UnitObject::renderer = renderer;
	Hex::renderer = renderer;
	SouthWest::renderer = renderer;
	SouthEast::renderer = renderer;
	East::renderer = renderer;
	NorthWest::renderer = renderer;
	NorthEast::renderer = renderer;
	West::renderer = renderer;

	Button::renderer = renderer;
	NextTurnButton::renderer = renderer;
	Settlement::renderer = renderer;
	Card::renderer = renderer;
	Card::card_tex = TexManager::load_texture(CARD_PATH, renderer);

	NextTurnButton::next_turn_tex = TexManager::load_texture(NEXT_TURN_PATH, renderer);
	Button::button_tex = TexManager::load_texture(NEXT_TURN_PATH, renderer);

	UnitObject::unit_tex = TexManager::load_texture(UNIT_PATH, renderer);
	Hex::hex_tex = TexManager::load_texture(HEX_PATH, renderer);
	Arena::arena_tex = TexManager::load_texture(ARENA_PATH, renderer);
	Trader::trader_tex = TexManager::load_texture(TRADER_PATH, renderer);


	SouthWest::sw_tex = TexManager::load_texture(UPR_PATH, renderer);
	SouthEast::se_tex = TexManager::load_texture(UPL_PATH, renderer);
	West::west_tex = TexManager::load_texture(UP_PATH, renderer);
	NorthWest::nw_tex = TexManager::load_texture(UPL_PATH, renderer);
	NorthEast::ne_tex = TexManager::load_texture(UPR_PATH, renderer);
	East::east_tex = TexManager::load_texture(UP_PATH, renderer);
}


void Game::clean()
{
	// TODO free all texes
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

bool Game::is_running()
{
	return game_running;
}

// TODO after this command class

void Game::find_path(ArrayPos cursor_pos, bool click) 
{
	
	std::shared_ptr<Player> active_player = players->get_active_player();
	//if () TODO if there is an active unit 
	std::shared_ptr<UnitObject>  active = active_player->get_active_unit(); 

	ArrayPos unit_pos = active->get_pos();
	int movement = active->get_movement();

	std::shared_ptr<Path> path = WQ_map->find_path(unit_pos, cursor_pos, click); 


	if (click) active->set_move_path(path);
	else       active->set_tentative_path(path);

	
	WQ_map->set_path(*path, click);
	
}
// TODO change name to click 
void Game::move_unit(ArrayPos cursor_pos)
{

	std::shared_ptr<Player> active_player = players->get_active_player();

	// TODO if there is an active unit
	std::shared_ptr<UnitObject>  active = active_player->get_active_unit();
	
	if (active->has_path()) {
		
		WQ_map->clear_path(*active->get_path());
	}

	find_path(cursor_pos, true);

	
	std::shared_ptr<Path> passed_pos = active->move();
	WQ_map->move_unit(active, passed_pos);
}

void Game::next_turn()
{
	

	std::vector<std::shared_ptr<Path>> all_passed  = players->next_turn();
	std::vector<std::shared_ptr<UnitObject>>* units = players->get_active_player()->get_units();

	

	if (units->size() != all_passed.size()) {
		// TODO error case 
		exit(1);
	}


	for (unsigned i = 0; i < units->size(); i++) {
		WQ_map->move_unit(units->at(i), all_passed[i]);
	}
	// NEXT TURN FOR MAP TO GROW AROUND PIVOT

}

void Game::use_settlement()
{
	std::shared_ptr<Player> active_player = players->get_active_player();
	std::shared_ptr<UnitObject>  active_unit = active_player->get_active_unit();
	ArrayPos unit_pos = active_unit->get_pos();

	std::shared_ptr<City> city = WQ_map->get_city(unit_pos);
	if (city == NULL) return;

	auto new_units = city->use_settlement(active_unit); // todo typedef

	if (new_units->size() == 1 and new_units->front() == active_unit) kill_unit(active_player, active_unit);

	for (auto it = new_units->begin(); it != new_units->end(); it++) {
		active_player->create_unit(*it);
		WQ_map->assign_unit(*it);
	}


}

void Game::kill_unit(std::shared_ptr<Player> player, std::shared_ptr<UnitObject> unit)
{
	WQ_map->kill_unit(unit);
	player->kill_unit(unit);
}



/*
// TODO add memoization comment
std::queue<ArrayPos> Game::walk_path(ArrayPos unit_pos, ArrayPos dest, int movement)
{
	
	
}

std::queue<ArrayPos> Game::walk_path(ArrayPos unit_pos, ArrayPos dest, int movement, )
{


}
*/
