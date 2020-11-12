#ifndef SOUTH_H
#define SOUTH_H
#include "PathPoint.h"
#include <iostream>

class South : public PathPoint
{
public:

	South() : PathPoint(PathEnum::S) {};

	void render(SDL_Rect& dest) override { // Code for south
		SDL_Rect arrow;
		arrow.h = dest.h / 2;
		arrow.w = dest.w / 20;
		arrow.x = dest.x + dest.w / 2 - arrow.w / 2;
		arrow.y = dest.y + arrow.h;
		SDL_RenderCopy(renderer, south_tex, NULL, &arrow);
	}

	static SDL_Renderer* renderer;
	static SDL_Texture* south_tex;

};

#endif

