#ifndef ARENA_H
#define ARENA_H

#include <list>
#include "UnitObject.h"
#include "Settlement.h"
#include "Battle.h"

// Arena is one the settlements in the game
// Using it will initiate a battle

class Arena : public Settlement
{

public:
	Arena(ArrayPos pos, int level);
	
	void render(SDL_Rect& dest);
	std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> use(std::shared_ptr<UnitObject>  unit);

	static SDL_Texture* arena_tex;
	static std::shared_ptr<Battle> battle;



private:

	std::shared_ptr<UnitObject> fighter;

};

#endif

