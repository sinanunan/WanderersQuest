#ifndef NORTH_EAST_H
#define NORTH_EAST_H
#include "PathPoint.h"
#include <iostream>

class NorthEast : public PathPoint
{
public:

	NorthEast() : PathPoint(PathEnum::NE) {};

	void render(SDL_Rect& dest) override {
		SDL_Rect arrow;
		arrow.h = dest.h / 2;
		arrow.w = dest.w / 2;
		arrow.x = dest.x + arrow.w;
		arrow.y = dest.y;
		SDL_RenderCopy(renderer, ne_tex, NULL, &arrow);
	}

	static SDL_Renderer* renderer;
	static SDL_Texture* ne_tex;

};

#endif

