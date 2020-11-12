#ifndef SOUTHWEST_H
#define SOUTHWEST_H
#include "PathPoint.h"
#include <iostream>

// SouthWest arrow inherited from the superclass pathpoint

class SouthWest : public PathPoint
{
public:	
	
	SouthWest() : PathPoint(PathEnum::SW) {};

	void render(SDL_Rect &dest) override { // Code for south
		SDL_Rect arrow;
		arrow.h = dest.h / 2;
		arrow.w = dest.w / 2;
		arrow.x = dest.x + 20;
		arrow.y = dest.y + dest.h / 2;
		SDL_RenderCopy(renderer, sw_tex, NULL, &arrow);
	}

	static SDL_Renderer* renderer; 
	static SDL_Texture* sw_tex;

};

#endif

