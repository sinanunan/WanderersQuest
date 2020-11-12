#ifndef NORTH_WEST_H
#define NORTH_WEST_H
#include "PathPoint.h"
#include <iostream>

// NorthWest arrow inherited from the superclass pathpoint

class NorthWest : public PathPoint
{
public:

	NorthWest() : PathPoint(PathEnum::NW) {};

	void render(SDL_Rect& dest) override {
		SDL_Rect arrow;
		arrow.h = dest.h / 2;
		arrow.w = dest.w /2;
		arrow.x = dest.x + 20;
		arrow.y = dest.y;
		SDL_RenderCopy(renderer, nw_tex, NULL, &arrow);
	}

	static SDL_Renderer* renderer;
	static SDL_Texture* nw_tex;

};

#endif

