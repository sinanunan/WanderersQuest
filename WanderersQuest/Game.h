#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Map.h"
#include "PlayerList.h"
#include "City.h"
#include <vector>
#include <queue>
#include "Path.h"
#include "Cards.h"
#include "UI.h"
#include "Arena.h"
#include "Trader.h"

class Game
{
public:
	Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	~Game();

	void init_game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen); //TODO make private

	void init_tex();

	void pre_command();
	void handle_events();
	void update();
	void render();
	void clean();

	bool is_running();

	void move_unit(ArrayPos Cursor_pos);
	void find_path(ArrayPos Cursor_pos, bool click);
	void next_turn();
	void use_settlement();

	void kill_unit(std::shared_ptr<Player> player, std::shared_ptr<UnitObject> unit); // private and in commands class

private:
	bool game_running;
	int count;

	Dimension game_dim;

	Map* WQ_map;
	PlayerList* players; // TODO make shared
	std::shared_ptr<Cards> cards;

	std::unique_ptr<UI> ui;


	SDL_Texture* player_tex;

	SDL_Window* window;
	SDL_Renderer* renderer;

	const double map_wind_ratio = 0.8;

	const char* UNIT_PATH = "assets/player.png"; //TODO look change name
	const char* HEX_PATH = "assets/hex.png";
	const char* ARENA_PATH = "assets/arena.png";
	const char* TRADER_PATH = "assets/trader.png";
	const char* CARD_PATH = "assets/card.png";

	const char* UPR_PATH = "assets/upright.png";
	const char* UPL_PATH = "assets/upleft.png";
	const char* UP_PATH = "assets/left.png";

	const char* NEXT_TURN_PATH = "assets/circle.png";


};

#endif