#include "City.h"



City::City(int level, std::vector<ArrayPos> span)
{
	int city_size = span.size();

	for (int i = 0; i < city_size; i++) {
		SettlementEnum settle = random_settlement();
		settlements.push_back(Settlement::make_settlement(settle, span[i], level));
	}

}

SettlementEnum City::random_settlement()
{
	int num = rand() % TOTAL_CHANCE;
	
	int counter = ARENA_CHANCE;
	if (num < counter) return SettlementEnum::ARENA;
	
	counter += TRADER_CHANCE;
	if (num < counter) return SettlementEnum::TRADER;

	return SettlementEnum::TRAINER;

}


void City::render(SDL_Rect& dest)
{
	for (auto it = settlements.begin(); it != settlements.end(); it++) {
		(*it)->render(dest);
	}
}

std::shared_ptr<std::list<std::shared_ptr<UnitObject>>> City::use_settlement(std::shared_ptr<UnitObject>  unit)
{
	ArrayPos pos = unit->get_pos();
	
	bool found = false;
	auto it = settlements.begin();

	while (not found) {
		if ((*it)->get_pos() == pos) found = true;
		else it++;
	}
	return (*it)->use(unit);
}

bool City::is_completed()
{
	for (auto it = settlements.begin(); it != settlements.end(); it++) {
		if ((*it)->is_visited() == false)
			return false;
	}
	return true;
}
