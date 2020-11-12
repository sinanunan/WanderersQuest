#include "Hex.h"


SDL_Renderer* Hex::renderer = NULL;
SDL_Texture* Hex::hex_tex = NULL;
SDL_Texture* Hex::tentative_tex = NULL;
SDL_Texture* Hex::path_tex = NULL;

Hex::Hex()
{
	unit = NULL;
	tentative_path = NULL;
	settlement = NULL;
}

void Hex::render(SDL_Rect& dest) const
{
	SDL_RenderCopy(renderer, hex_tex, NULL, &dest); 
	
	if (settlement != NULL) {
		std::cout << "settle" << std::endl;
		settlement->render(dest);
	}

	if (not move_path.empty()) {
		for (auto it = move_path.begin(); it != move_path.end(); it++) {
			(*it)->render(dest);
		}
	}
	if (tentative_path != NULL) {
		tentative_path->render(dest);
	}

	if (has_unit()) {
		unit->render(dest);
	}
}

void Hex::pre_command()
{
	tentative_path = NULL;
}

void Hex::remove_path(PathEnum dir) { 
	for (auto it = move_path.begin(); it != move_path.end(); it++) {
		if (**it == dir) {
			move_path.erase(it);
			return;
		}
	}
};


