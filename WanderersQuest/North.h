#ifndef NORTH_H
#define NORTH_H
#include "PathPoint.h"
#include <iostream>

class North : public PathPoint
{
public:

	North() : PathPoint(PathEnum::N) {};

	void render(SDL_Rect& dest) override {
		SDL_Rect arrow;
		arrow.h = dest.h / 2;
		arrow.w = dest.w / 20;
		arrow.x = dest.x + dest.w / 2 - arrow.w / 2;
		arrow.y = dest.y;
		SDL_RenderCopy(renderer, north_tex, NULL, &arrow);
	}

	static SDL_Renderer* renderer;
	static SDL_Texture* north_tex;

};

#endif

