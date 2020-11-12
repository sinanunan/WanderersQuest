#include "NextTurnButton.h"


SDL_Texture* NextTurnButton::next_turn_tex = NULL;
SDL_Renderer* NextTurnButton::renderer = NULL;

NextTurnButton::NextTurnButton(SDL_Rect& ui_rect)
{
	next_turn_rect.h = ui_rect.w;
	//next_turn_rect.w = game_dim.w * GAME_NEXT_RATIO_W; // TODO make a kare
	next_turn_rect.w = next_turn_rect.h;

	next_turn_rect.x = ui_rect.x;
	next_turn_rect.y = ui_rect.y - next_turn_rect.h + ui_rect.h;

	


}

void NextTurnButton::render()
{

	SDL_RenderCopy(renderer, next_turn_tex, NULL, &next_turn_rect);

}

bool NextTurnButton::cursor_on(Coor cursor_coor)
{
	int radius = next_turn_rect.w / 2;
	
	Coor relative_cursor;
	relative_cursor.y = cursor_coor.y - (next_turn_rect.y + next_turn_rect.h / 2);
	relative_cursor.x = cursor_coor.x - (next_turn_rect.x + next_turn_rect.w / 2);

	int x_min_a = std::sqrt((radius + relative_cursor.y) * (radius - relative_cursor.y));

	int expected_x1 = - x_min_a;
	int expected_x2 = x_min_a;
	
	return (relative_cursor.x > expected_x1 and relative_cursor.x < expected_x2);
	 
}