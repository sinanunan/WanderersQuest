#include <stdlib.h>
#include <iostream>
#include "Game.h"

const int FPS = 60;
const int frame_delay = 1000 / FPS;

int main(int argc, char* argv[])
{

	int height = 1800;
	int width = 900;
	
	Game* WQ_game = new Game("Wanderer's Quest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, false);


	while (WQ_game->is_running()) {
	
		int frame_before = SDL_GetTicks();
		
		WQ_game->pre_command();
		WQ_game->handle_events();
		WQ_game->update();
		WQ_game->render();

		int frame_time = SDL_GetTicks() - frame_before;

		if (frame_delay > frame_time) {
			SDL_Delay(frame_delay - frame_time);
		}
	}

	WQ_game->clean();

	return EXIT_SUCCESS;
}
