#include "Hex.h"


SDL_Renderer* Hex::renderer = NULL;
SDL_Texture* Hex::hex_tex = NULL;

Hex::Hex()
{
	unit = NULL;
	tentative_path = NULL;
	city = NULL;
}

Hex::Hex(const Hex& copy)
{
	unit = NULL;
	tentative_path = NULL;
	city = NULL;
}

void Hex::render(SDL_Rect& dest) const
{
	//std::cout << "in render hex\n";
	SDL_RenderCopy(renderer, hex_tex, NULL, &dest); 
	
	if (city != NULL) {
		//std::cout << "hi\n";
		city->render(dest);
	}

//	std::cout << "af render city hex\n";
	if (not move_path.empty()) {
		for (auto it = move_path.begin(); it != move_path.end(); it++) {
			(*it)->render(dest);
		}
	}


	//std::cout << "after render path hex\n";
	if (tentative_path != NULL) {
		tentative_path->render(dest);
	}

	//std::cout << "af render tent path hex\n";

	if (has_unit()) {
		unit->render(dest);
	}
	//std::cout << "af render hex\n";
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


