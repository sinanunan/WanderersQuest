#ifndef NEXT_TURN_BUTTON_H
#define NEXT_TURN_BUTTON_H

#include "CoorTypes.h"
#include "SDL.h"
#include <cmath>

class NextTurnButton
{
public:
	NextTurnButton(SDL_Rect& ui_rect);

	static SDL_Texture* next_turn_tex;
	static SDL_Renderer* renderer;

	void render();

	bool cursor_on(Coor cursor_coor);

private:

	// Next turn;

	const double NEXT_UI_RATIO_H = 0.85;

	SDL_Rect next_turn_rect;



};


#endif

