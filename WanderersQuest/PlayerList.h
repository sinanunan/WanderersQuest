#ifndef PLAYER_LIST_H
#define PLAYER_LIST_H

#include "Player.h"
#include <vector>

class PlayerList
{
public:

	PlayerList(int player_num, std::shared_ptr<Cards> cards);
	~PlayerList();

	std::vector<std::shared_ptr<UnitObject>> assign_starters(std::vector<ArrayPos> starting_pos);


	void render();

	std::shared_ptr<Player> get_active_player() { return player_arr[active_player]; };

	std::vector<std::shared_ptr<Path>> next_turn();


private:
	
	int player_num;
	std::vector<std::shared_ptr<Player>> player_arr;

	const int active_player = 0; // TODO for multiplayer

};

#endif 

