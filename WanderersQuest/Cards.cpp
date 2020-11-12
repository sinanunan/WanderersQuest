#include "Cards.h"

Cards::Cards(Dimension game_dim)
{
	card_window.h = game_dim.h * GAME_CARDS_RATIO_H;
	card_window.w = game_dim.w * GAME_CARDS_RATIO_W;

	cards_start.x = (game_dim.w - card_window.w) / 2;
	cards_start.y = (game_dim.h - card_window.h);


	Card::card_w = card_window.w / full_card_lim;
	Card::card_h = card_window.h;

	card_dist = calculate_card_dist();
	starting_x = get_starting_x();


}

void Cards::render()
{
	Coor starting_loc;
	starting_loc.y = cards_start.y;
	
	
	
	double card_x = starting_x;

	for (auto it = all_cards.begin(); it != all_cards.end(); it++) {
		starting_loc.x = card_x;
		it->render(starting_loc);
		card_x += card_dist;
	}

}

void Cards::update()
{
	for (auto it = all_cards.begin(); it != all_cards.end(); it++) {
		it->update();
	}
}

double Cards::calculate_card_dist() const
{
	int num_cards = all_cards.size();
	if (num_cards <= full_card_lim) return Card::card_w;
	else {
		return (double(card_window.w) - Card::card_w) / (double(num_cards) - 1);
	}

}

int Cards::get_starting_x() const
{
	int num_cards = all_cards.size();
	if (num_cards >= full_card_lim) return cards_start.x;
	else {
		int offset = (full_card_lim - num_cards) * (Card::card_w / 2);
		return cards_start.x + offset;
	}

}

void Cards::create_card(std::shared_ptr<UnitObject>  unit)
{
	Card temp(unit);
	all_cards.push_back(temp);
	starting_x = get_starting_x();
	card_dist = calculate_card_dist();

}

void Cards::kill_card(std::shared_ptr<UnitObject>  unit)
{
	for (auto it = all_cards.begin(); it != all_cards.end(); it++) {
		if (it->get_unit() == unit) {
			all_cards.erase(it);
			break;
		}
	}

	starting_x = get_starting_x();
	card_dist = calculate_card_dist();

}

bool Cards::cursor_on(Coor cursor_coor)
{
	bool on = false;
	for (auto it = all_cards.rbegin(); it != all_cards.rend(); it++) {
		if (it->cursor_on(cursor_coor)) {
			it->animate_raise();
			on = true;
		}
		else {
			it->cancel_anim();
		}
	}
	return on;
	
	
}