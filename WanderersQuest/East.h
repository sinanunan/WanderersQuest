#ifndef EAST_H
#define EAST_H
#include "PathPoint.h"
#include <iostream>

// East arrow inherited from the superclass pathpoint

class East : public PathPoint
{
public:

	East() : PathPoint(PathEnum::E) {};

	void render(SDL_Rect& dest) override {
		SDL_Rect arrow;
		arrow.h = dest.h / 10;
		arrow.w = dest.w / 2;
		arrow.x = dest.x + dest.w / 2;
		arrow.y = dest.y + dest.h / 2 - arrow.h / 2;
		SDL_RenderCopy(renderer, east_tex, NULL, &arrow);
	}

	static SDL_Renderer* renderer;
	static SDL_Texture* east_tex;

};

#endif

