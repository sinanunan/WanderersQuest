#include "Player.h"

Player::Player(std::shared_ptr<Cards> cards) : cards(cards)
{
	// TODO add starting unit based on player type (country)
	
	active_unit_pos = 0;

}


std::shared_ptr<UnitObject> Player::assign_starter(ArrayPos starter_pos)
{
	std::shared_ptr<UnitObject> starter = std::make_shared<UnitObject>(starter_pos);
	units.push_back(starter);
	cards->create_card(starter);

	return starter;


}

Player::~Player()
{

}


//std::vector<std::vector<ArrayPos>> Player::next_turn(std::vector<UnitObject>& unit_list) // TODO add updates
std::vector<std::shared_ptr<Path>> Player::next_turn()
{
	int unit_count = units.size();
	std::vector<std::shared_ptr<Path>> all_passed(unit_count);
	for (int i = 0; i < unit_count; i++) {
		all_passed[i] = units[i]->next_turn();
	}

	return all_passed;
}

void Player::next_turn_ai() // TODO add updates
{
	for (auto it = units.begin(); it != units.end(); it++) {
		(*it)->next_turn();
	}
}

std::shared_ptr<UnitObject>  Player::get_next_unit()
{
	cycle_active_unit();
	return get_active_unit();
}


void Player::cycle_active_unit()
{
	active_unit_pos = ++active_unit_pos % units.size();
}

std::shared_ptr<UnitObject> Player::create_unit(ArrayPos pos)
{
	std::shared_ptr<UnitObject> unit = std::make_shared<UnitObject>(pos);
	
	return create_unit(unit);
}


void Player::kill_unit(std::shared_ptr<UnitObject> unit)
{
	cards->kill_card(unit);
	units.erase(std::remove(units.begin(), units.end(), unit), units.end());

}

std::shared_ptr<UnitObject>  Player::create_unit(std::shared_ptr<UnitObject> unit)
{
	units.push_back(unit);

	cards->create_card(unit);

	return units.back();
}

void Player::render()
{
	cards->render();
}
