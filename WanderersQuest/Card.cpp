#include "Card.h"


SDL_Renderer* Card::renderer = NULL;
SDL_Texture* Card::card_tex = NULL;


int Card::card_h = 0;
int Card::card_w = 0;


Card::Card(std::shared_ptr<UnitObject>  unit) : unit(unit)
{
	dest.h = card_h;
	dest.w = card_w;

	raise = 0;
	anim_up = false;
	anim_down = false;
}

void Card::render(Coor starting_loc)
{
	dest.x = starting_loc.x;
	dest.y = starting_loc.y - raise; 

	SDL_RenderCopy(renderer, card_tex, NULL, &dest);
}

void Card::update()
{
	

	if (anim_up) {
		if (raise != max_raise) raise += anim_rate;
		else anim_up = false;
	}
	else if (anim_down) {
		if (raise != 0) raise -= anim_rate;
		else anim_down = false;
	}
}

bool Card::cursor_on(Coor cursor_coor) {
	if (cursor_coor.x > dest.x and cursor_coor.x < dest.x + dest.w and
		cursor_coor.y > dest.y) return true;
	return false;
}

void Card::animate_raise()
{
	anim_up = true;
}