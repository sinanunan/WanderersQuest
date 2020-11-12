#ifndef CARD_H
#define CARD_H

#include "SDL.h"
#include "CoorTypes.h"
#include "UnitObject.h"

class Card
{
public:

	Card(std::shared_ptr<UnitObject>  unit);

	static int card_h;
	static int card_w;

	static SDL_Renderer* renderer;
	static SDL_Texture* card_tex;

	void render(Coor starting_loc);
	void update();

	bool cursor_on(Coor cursor_coor);
	void animate_raise();
	void cancel_anim() { anim_up = false; anim_down = true; };

	std::shared_ptr<UnitObject> get_unit() { return unit; };

private:

	SDL_Rect dest;

	bool anim_up;
	bool anim_down;
	int raise;
	const int max_raise = 100;
	const int anim_rate = 5;


	std::shared_ptr<UnitObject>  unit; // TODO
};

#endif

