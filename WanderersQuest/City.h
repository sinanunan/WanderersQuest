#ifndef CITY_H
#define CITY_H

#include "SDL.h"
#include "UnitObject.h"
#include "CoorTypes.h"
#include <list>
#include "Settlement.h"
#include "SettlementEnum.h"
#include <vector>

class City
{
public:

	City(int level, std::vector<ArrayPos> span);
	
	void render(SDL_Rect& dest);

	std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> use_settlement(std::shared_ptr<UnitObject>  unit);

	bool is_completed();

private:
 
	std::list<std::unique_ptr<Settlement>> settlements;

	static SettlementEnum random_settlement();

	static const int ARENA_CHANCE = 25;
	static const int TRADER_CHANCE = 40;
	static const int TRAINER_CHANCE = 0;

	static const int TOTAL_CHANCE = ARENA_CHANCE + TRADER_CHANCE + TRAINER_CHANCE;

};

#endif

