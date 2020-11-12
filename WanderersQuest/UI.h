#ifndef UI_H
#define UI_H

#include "NextTurnButton.h"
#include <vector>
#include "Button.h"
#include "CoorTypes.h"
#include "SDL.h"

class UI
{

public:

	UI(Dimension game_dim);
	void render();

	bool cursor_on(Coor cursor_coor);

private:

	const int num_buttons = 5;


	const double UI_GAME_RATIO_H = 0.40;
	const double UI_GAME_RATIO_W = 0.15;
	const double UI_BUTTON_RATIO = 0.15;

	

	std::vector<Button> buttons;
	std::unique_ptr<NextTurnButton> next;

};

#endif

