#include "Trader.h"


SDL_Texture* Trader::trader_tex = NULL;


Trader::Trader(ArrayPos pos, int level) : Settlement(pos, level)
{
	
}

void Trader::render(SDL_Rect& dest)
{
	SDL_RenderCopy(renderer, trader_tex, NULL, &dest);
}

std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> Trader::use(std::shared_ptr<UnitObject>  unit)
{
	
	// todo create card
	std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> new_units = std::make_shared<std::list<std::shared_ptr<UnitObject>>>(); // TODO typedef

	if (visited) return new_units;
	new_units->push_back(UnitObject::generate_unit(pos, level));

	visited = true;

	return new_units;
}
