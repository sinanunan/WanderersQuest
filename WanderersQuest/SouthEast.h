#ifndef SOUTH_EAST_H
#define SOUTH_EAST_H
#include "PathPoint.h"
#include <iostream>

// SouthEast arrow inherited from the superclass pathpoint

class SouthEast : public PathPoint
{
public:

	SouthEast() : PathPoint(PathEnum::SE) {};

	void render(SDL_Rect& dest) override { 
		SDL_Rect arrow;
		arrow.h = dest.h / 2;
		arrow.w = dest.w / 2;
		arrow.x = dest.x + arrow.w;
		arrow.y = dest.y + dest.h / 2;
		SDL_RenderCopy(renderer, se_tex, NULL, &arrow);
	}

	static SDL_Renderer* renderer;
	static SDL_Texture* se_tex;

};

#endif

