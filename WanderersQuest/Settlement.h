#ifndef SETTLEMENT_H
#define SETTLEMENT_H

#include "SDL.h"

class Settlement
{
public:

	Settlement();

	void render(SDL_Rect& dest);

	static SDL_Renderer* renderer;
	static SDL_Texture* settle_tex;


private:
 
	bool visited;
};

#endif

