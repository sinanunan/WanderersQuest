#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "SDL.h"

class Button
{
public:


	Button(SDL_Rect rect, std::string name);

	void render();

	static SDL_Texture* button_tex;
	static SDL_Renderer* renderer;
	
private:

	std::string name;
	SDL_Rect dest;
};

#endif
