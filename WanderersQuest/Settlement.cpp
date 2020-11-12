#include "Settlement.h"


SDL_Renderer* Settlement::renderer = NULL;
SDL_Texture* Settlement::settle_tex = NULL;

Settlement::Settlement()
{

}


void Settlement::render(SDL_Rect& dest)
{
	SDL_RenderCopy(renderer, settle_tex, NULL, &dest);
}