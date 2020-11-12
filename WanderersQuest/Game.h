#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Map.h"
#include "PlayerList.h"
#include "Settlement.h"
#include <vector>
#include <queue>
#include "Path.h"

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

private:
	bool game_running;
	int count;

	Dimension game_dim;

	Map* WQ_map;
	PlayerList* players;

	SDL_Texture* player_tex;

	SDL_Window* window;
	SDL_Renderer* renderer;

	const float map_wind_ratio = 0.8;

	const char* UNIT_PATH = "assets/player.png"; //TODO look change name
	const char* HEX_PATH = "assets/hex.png";
	const char* TENTATIVE_PATH = "assets/tentative.png";
	const char* PATH_PATH = "assets/path.png";
	const char* SETTLE_PATH = "assets/city.png";

	const char* UPR_PATH = "assets/upright.png";
	const char* UPL_PATH = "assets/upleft.png";
	const char* UP_PATH = "assets/up.png";


};

#endif