#ifndef WEST_H
#define WEST_H
#include "PathPoint.h"
#include <iostream>

// West arrow inherited from the superclass pathpoint

class West : public PathPoint
{
public:

	West() : PathPoint(PathEnum::W) {};

	void render(SDL_Rect& dest) override {
		SDL_Rect arrow;
		arrow.h = dest.h / 10;
		arrow.w = dest.w / 2;
		arrow.x = dest.x;
		arrow.y = dest.y + dest.h / 2 - arrow.h / 2;
		SDL_RenderCopy(renderer, west_tex, NULL, &arrow);
	}

	static SDL_Renderer* renderer;
	static SDL_Texture* west_tex;

};

#endif

