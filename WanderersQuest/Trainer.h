#ifndef TRAINER_H
#define TRAINER_H

#include "Settlement.h"
#include "SDL.h"
#include "SkillList.h"

class Trainer : public Settlement
{
public:
	Trainer(ArrayPos pos, int level);

	void render(SDL_Rect& dest);
	std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> use(std::shared_ptr<UnitObject>  unit);


	static SDL_Texture* trainer_tex;

private:

	const int specific_trainer_boost = 10;
	const int random_trainer_boost = 20;

};


#endif


