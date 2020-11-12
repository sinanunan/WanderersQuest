#include "PlayerList.h"


PlayerList::PlayerList(int player_num) :
	player_num(player_num)
{
	player_arr.resize(player_num);

}

PlayerList::~PlayerList()
{

}

std::vector<Path> PlayerList::next_turn()

{
	std::vector<Path> to_return;
	for (int i = 0; i < player_num; i++) {
		if (i == active_player) {
			to_return = player_arr[i].next_turn();
		}
		else {
			player_arr[i].next_turn_ai();
		}
	}

	return to_return;
}