#include "Trainer.h"


SDL_Texture* Trainer::trainer_tex = NULL;

Trainer::Trainer(ArrayPos pos, int level) : Settlement(pos, level)
{
	
}

void Trainer::render(SDL_Rect& dest)
{
	SDL_RenderCopy(renderer, trainer_tex, NULL, &dest);
}

std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> Trainer::use(std::shared_ptr<UnitObject>  unit)
{

	
	// todo create card
	std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> new_units = std::make_shared<std::list<std::shared_ptr<UnitObject>>>(); // TODO typedef

	if (visited) return new_units;

	Skill random = SkillList::random_skill();
	// TODO unit->increase_skill(random, );


	visited = true;

	return new_units;
}
