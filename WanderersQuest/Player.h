#ifndef PLAYER_H
#define PLAYER_H

#include "UnitObject.h"
#include <Vector>
#include "Path.h"
#include "Cards.h"

class Player
{

public:

	Player(std::shared_ptr<Cards> cards);
	~Player();

	std::shared_ptr<UnitObject> assign_starter(ArrayPos starter_pos);

	void render();

	std::vector<std::shared_ptr<UnitObject>>* get_units() { return &units; };

	bool has_active_unit() const { return (active_unit_pos + 1); };
	std::shared_ptr<UnitObject>  get_active_unit() { return units[active_unit_pos]; };
	std::shared_ptr<UnitObject>  get_next_unit();
	void kill_unit(std::shared_ptr<UnitObject> unit);

	std::shared_ptr<UnitObject>  create_unit(ArrayPos pos);
	std::shared_ptr<UnitObject>  create_unit(std::shared_ptr<UnitObject> unit);


	std::vector<std::shared_ptr<Path>> next_turn();

	
	void next_turn_ai();

private:
	// faction/skill
	// unit array
	std::vector<std::shared_ptr<UnitObject>> units;
	int active_unit_pos;

	void cycle_active_unit();
	std::shared_ptr<Cards> cards;

};

#endif