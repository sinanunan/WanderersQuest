#include "UnitObject.h"
#include <iostream>

SDL_Renderer* UnitObject::renderer = NULL; 
SDL_Texture* UnitObject::unit_tex = NULL;


UnitObject::UnitObject()
{
	 
	unit_pos.c = 0;
	unit_pos.r = 0;
	// TODO random or not starting loc
	// TODO initialize movemenet function vb, vb,
	movement = 2;
	moves_left = movement;
	//player_num;

	
}

UnitObject::UnitObject(const ArrayPos starting_loc)
{

	unit_pos = starting_loc;
	// TODO random or not starting loc
	// TODO initialize movemenet function vb, vb,
	movement = 2; // TODO default movement
	moves_left = movement;
	//player_num;


}

// all knowledge comes from dest
void UnitObject::render(const SDL_Rect& hex) const
{
	SDL_Rect unit_rect;
	unit_rect.h = hex.h * HEX_UNIT_RATIO_H;
	unit_rect.w = hex.h * HEX_UNIT_RATIO_W;

			   //  finds the middle --- aligns middle of player with middle of hex
	unit_rect.x = (hex.x + hex.w / 2) - (unit_rect.w / 2);
	unit_rect.y = (hex.y + hex.h / 2) - (unit_rect.h / 2);
	
	SDL_RenderCopy(renderer, unit_tex, NULL, &unit_rect);
}

Path UnitObject::next_turn()
{
	// TODO 
	
	moves_left = movement;
	Path passed_pos;
	if (has_path()) {
		passed_pos = move();
	}
	return passed_pos;
}

// TODO Animate move
Path UnitObject::move()
{
	Path passed_pos(unit_pos);

	while (not move_path.empty() and moves_left != 0) {

		unit_pos = move_path.pop();
		passed_pos.push(unit_pos);

		moves_left--;
	}
	return passed_pos;

}


// TODO next turn ai
void UnitObject::move_ai()
{

	while (not move_path.empty() and moves_left != 0) {

		unit_pos = move_path.pop();

		moves_left--;
	}

}



