#include "Arena.h"


SDL_Texture* Arena::arena_tex = NULL;
std::shared_ptr<Battle> Arena::battle = NULL;

Arena::Arena(ArrayPos pos, int level) : Settlement(pos, level)
{
	fighter = UnitObject::generate_unit(pos, level);
}

void Arena::render(SDL_Rect& dest) 
{
	SDL_RenderCopy(renderer, arena_tex, NULL, &dest);
}

std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> Arena::use(std::shared_ptr<UnitObject>  unit)
{

	std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> new_units = std::make_shared<std::list<std::shared_ptr<UnitObject>>>(); // TODO typedef

	if (visited) return new_units;

	BATTLE_RESULT res = Battle::single_fight(unit, fighter);

	if (res == BATTLE_RESULT::CAPTURE) {
		new_units->push_back(fighter);
	}

	visited = true;
	
	return new_units;
}
