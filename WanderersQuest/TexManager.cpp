#include "TexManager.h"

SDL_Texture* TexManager::load_texture(const char* filename, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return tex;
}