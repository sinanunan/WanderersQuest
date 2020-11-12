#ifndef CARDS_H
#define CARDS_H

#include "SDL.h"
#include "CoorTypes.h"
#include <list>
#include "Card.h"

class Cards
{
public:

	Cards(Dimension game_dim);

	void create_card(std::shared_ptr<UnitObject>  unit);

	void kill_card(std::shared_ptr<UnitObject> unit);
	bool cursor_on(Coor cursor_coor);

	void render();
	void update();


	const double GAME_CARDS_RATIO_H = 0.2;
	const double GAME_CARDS_RATIO_W = 0.8;


private:

	Dimension card_window;
	Coor cards_start;

	double card_dist;
	double starting_x;

	const int full_card_lim = 5;

	double calculate_card_dist() const;
	int get_starting_x() const;

	std::list<Card> all_cards;
};

#endif 