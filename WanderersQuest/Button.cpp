#include "Button.h"


SDL_Texture* Button::button_tex = NULL;
SDL_Renderer* Button::renderer = NULL;

Button::Button(SDL_Rect rect, std::string name) : 
	dest(rect), name(name)
{

}

void Button::render()
{
	SDL_RenderCopy(renderer, button_tex, NULL, &dest);
}