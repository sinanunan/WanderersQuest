#include "Player.h"

Player::Player()
{
	// TODO add starting unit based on player type (country)
	
	UnitObject starter;
	units.push_back(starter);

	active_unit_pos = 0;
}

Player::~Player()
{

}


//std::vector<std::vector<ArrayPos>> Player::next_turn(std::vector<UnitObject>& unit_list) // TODO add updates
std::vector<Path> Player::next_turn()
{
	int unit_count = units.size();
	std::vector<Path> all_passed(unit_count);
	for (int i = 0; i < unit_count; i++) {
		all_passed[i] = units[i].next_turn();
	}
	//unit_list = units;
	return all_passed;
}

void Player::next_turn_ai() // TODO add updates
{
	for (auto it = units.begin(); it != units.end(); it++) {
		it->next_turn();
	}
}

UnitObject* Player::get_next_unit()
{
	std::cout << "hi\n";
	cycle_active_unit();
	std::cout << "hifs\n";
	return get_active_unit();
}


void Player::cycle_active_unit()
{
	active_unit_pos = ++active_unit_pos % units.size();
}

UnitObject* Player::create_unit(ArrayPos pos)
{
	UnitObject unit(pos);
	units.push_back(unit);
	return &units.back();
}