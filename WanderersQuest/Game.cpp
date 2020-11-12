#include "Game.h"
#include "TexManager.h"

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) // TODO add settings	
{
	count = 0;
	init_game(title, xpos, ypos, width, height, fullscreen);

	init_tex();

	game_dim.h = height;
	game_dim.w = width;

	Dimension dim(10, 10);
	Map::map_dim = dim;
	WQ_map = new Map(renderer);
	// TODO int num_players = create game // with settings
	int num_players = 1;
	players = new PlayerList(num_players);
	UnitObject* unit = new UnitObject;
	WQ_map->assign_unit(unit);
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
	SDL_GetMouseState(&cursor_coor.x, &cursor_coor.y);
	ArrayPos cursor_pos = WQ_map->find_cursor_hex(cursor_coor);
	find_path(cursor_pos, false); // TODO add cursor pos based on window // Find path assigns to hex when unit is active
	

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			game_running = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
		{
			move_unit(cursor_pos);
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
				UnitObject* unit = players->get_active_player()->create_unit(ArrayPos(5, 2));
				WQ_map->assign_unit(unit);
				break; }
			case SDLK_l:
				next_turn();
				break;
			case SDLK_n: {
				UnitObject* unit = players->get_active_player()->get_next_unit();
				WQ_map->grow_around_pivot(unit->get_pos(), true);
				break;
			}
			case SDLK_f:
				WQ_map->create_city();
			}
		}
	}
	
	
}

void Game::update()
{
	WQ_map->update();
	
	
	count++;
	//std::cout << count << std::endl;
}

void Game::render()
{
	
	SDL_RenderClear(renderer);

	WQ_map->render();
	
	SDL_RenderPresent(renderer);
	
}

void Game::init_tex()
{
	UnitObject::renderer = renderer;
	Hex::renderer = renderer;
	SouthWest::renderer = renderer;
	SouthEast::renderer = renderer;
	South::renderer = renderer;
	NorthWest::renderer = renderer;
	NorthEast::renderer = renderer;
	North::renderer = renderer;

	Settlement::renderer = renderer;


	UnitObject::unit_tex = TexManager::load_texture(UNIT_PATH, renderer);
	Hex::hex_tex = TexManager::load_texture(HEX_PATH, renderer);
	Hex::tentative_tex = TexManager::load_texture(TENTATIVE_PATH, renderer);
	Hex::path_tex = TexManager::load_texture(PATH_PATH, renderer);
	Settlement::settle_tex = TexManager::load_texture(SETTLE_PATH, renderer);

	SouthWest::sw_tex = TexManager::load_texture(UPR_PATH, renderer);
	SouthEast::se_tex = TexManager::load_texture(UPL_PATH, renderer);
	South::south_tex = TexManager::load_texture(UP_PATH, renderer);
	NorthWest::nw_tex = TexManager::load_texture(UPL_PATH, renderer);
	NorthEast::ne_tex = TexManager::load_texture(UPR_PATH, renderer);
	North::north_tex = TexManager::load_texture(UP_PATH, renderer);
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

void Game::find_path(ArrayPos cursor_pos, bool click) // TODO call in unit decide tbh
{
	
	Player* active_player = players->get_active_player();
	//if () TODO if there is an active unit 
	UnitObject* active = active_player->get_active_unit(); 

	ArrayPos unit_pos = active->get_pos();
	int movement = active->get_movement();

	Path path = WQ_map->find_path(unit_pos, cursor_pos, click); 


	if (click) active->set_move_path(path);
	else       active->set_tentative_path(path);

	WQ_map->set_path(path, click);
	
}
// TODO change name to click 
void Game::move_unit(ArrayPos cursor_pos)
{

	Player* active_player = players->get_active_player();
	
	// TODO if there is an active unit
	UnitObject* active = active_player->get_active_unit();
	// TODO typedef deque array pos

	if (active->has_path()) {
		
		WQ_map->clear_path(active->get_path());
	}

	find_path(cursor_pos, true);
	
	Path passed_pos = active->move();
	WQ_map->move_unit(active, passed_pos);
}

void Game::next_turn()
{
	

	std::vector<Path> all_passed  = players->next_turn();
	std::vector<UnitObject>* units = players->get_active_player()->get_units();

	

	if (units->size() != all_passed.size()) {
		// TODO error case 
		exit(1);
	}


	for (int i = 0; i < units->size(); i++) {
		WQ_map->move_unit(&units->at(i), all_passed[i]);
		WQ_map->clear_path(all_passed[i]);
	}

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
