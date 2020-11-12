#include "UI.h"


UI::UI(Dimension game_dim)
{
	SDL_Rect ui_rect;
	ui_rect.h = game_dim.h * UI_GAME_RATIO_H;
	ui_rect.w = game_dim.w * UI_GAME_RATIO_W;
	
	ui_rect.y = game_dim.h - ui_rect.h;
	ui_rect.x = game_dim.w - ui_rect.w;

	next = std::make_unique<NextTurnButton>(ui_rect);

	SDL_Rect temp_rect;
	temp_rect.w = ui_rect.w / (num_buttons * 2 - 1);
	temp_rect.h = ui_rect.h * UI_BUTTON_RATIO;
	temp_rect.x = ui_rect.x;
	temp_rect.y = ui_rect.y;
	
	for (int i = 0; i < num_buttons; i++) {
		Button but(temp_rect, "name");
		buttons.push_back(but);
		temp_rect.x += temp_rect.w * 2;
		

	}

}

void UI::render()
{
	next->render();
	for (int i = 0; i < num_buttons; i++) {
		buttons[i].render();

	}
}

bool UI::cursor_on(Coor cursor_coor)
{
	return next->cursor_on(cursor_coor);
}