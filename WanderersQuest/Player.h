#ifndef PLAYER_H
#define PLAYER_H

#include "UnitObject.h"
#include <Vector>
#include "Path.h"
class Player
{

public:

	Player();
	~Player();

	std::vector<UnitObject>* get_units() { return &units; };

	bool has_active_unit() const { return (active_unit_pos + 1); };
	UnitObject* get_active_unit() { return &units[active_unit_pos]; };
	UnitObject* get_next_unit();

	UnitObject* create_unit(ArrayPos pos);


	std::vector<Path> next_turn();

	
	void next_turn_ai();

private:
	// faction/skill
	// unit array
	std::vector<UnitObject> units;
	int active_unit_pos;

	void cycle_active_unit();
};

#endif