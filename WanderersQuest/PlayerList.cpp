#include "PlayerList.h"


PlayerList::PlayerList(int player_num, std::shared_ptr<Cards> cards) :
	player_num(player_num)
{
	player_arr.resize(player_num);
	for (int i = 0; i < player_num; i++) {
		player_arr[i] = std::make_shared<Player>(cards);
	}

}

std::vector<std::shared_ptr<UnitObject>> PlayerList::assign_starters(std::vector<ArrayPos> starting_pos)
{
	std::vector<std::shared_ptr<UnitObject>> all_starters;

	for (int i = 0; i < player_num; i++) {
		all_starters.push_back(player_arr[i]->assign_starter(starting_pos[i]));
	}
	return all_starters;
}

PlayerList::~PlayerList()
{

}

std::vector<std::shared_ptr<Path>> PlayerList::next_turn()
{
	std::vector<std::shared_ptr<Path>> to_return;
	for (int i = 0; i < player_num; i++) {
		if (i == active_player) {
			to_return = player_arr[i]->next_turn();
		}
		else {
			player_arr[i]->next_turn_ai();
		}
	}

	return to_return;
}

void PlayerList::render()
{
	player_arr[active_player]->render();
}