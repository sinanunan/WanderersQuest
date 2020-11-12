#pragma once

#include "Player.h"
#include <vector>

class PlayerList
{
public:

	PlayerList(int player_num);
	~PlayerList();

	Player* get_active_player() { return &player_arr[0]; };

	std::vector<Path> next_turn();


private:
	
	int player_num;
	std::vector<Player> player_arr;

	const int active_player = 0; // TODO for multiplayer

};

