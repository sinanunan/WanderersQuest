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

	//std::cout << "unit h:" << unit_rect.h << "      unit w:" << unit_rect.w << std::endl;
	//std::cout << "    center x: " << unit_rect.x + unit_rect.w << "    center y: " << unit_rect.y + unit_rect.h << "\n";
	
	SDL_RenderCopy(renderer, unit_tex, NULL, &unit_rect);
}

std::shared_ptr<Path> UnitObject::next_turn()
{
	// TODO 
	
	moves_left = movement;
	
	if (has_path()) {
		return move();
	}

	return std::make_shared<Path>();
}

// TODO Animate move
std::shared_ptr<Path> UnitObject::move()
{
	std::shared_ptr<Path> passed_pos = std::make_shared<Path>(unit_pos);
	
	while (not move_path->empty() and moves_left != 0) {
		unit_pos = move_path->pop();
		passed_pos->push(unit_pos);

		moves_left--;

	}
	return passed_pos;

}


// TODO next turn ai
void UnitObject::move_ai()
{

	while (not move_path->empty() and moves_left != 0) {

		unit_pos = move_path->pop();

		moves_left--;
	}

}

std::shared_ptr<UnitObject> UnitObject::generate_unit(ArrayPos start, int level)
{
	return std::make_shared<UnitObject>(start); // TODO
}



