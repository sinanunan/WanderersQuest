#ifndef UNIT_OBJECT_H
#define UNIT_OBJECT_H
#include "SDL.h"
#include "SDL_image.h"
#include "TexManager.h"
#include "SkillList.h"
#include "CoorTypes.h"
#include <queue>
#include "Path.h"

class UnitObject
{

public:
	UnitObject();
	UnitObject(ArrayPos starting_loc);
	

	static SDL_Renderer* renderer; // TODO do it for all or not
	static SDL_Texture* unit_tex;
	
	void render(const SDL_Rect& hex) const;

	ArrayPos get_pos() const { return unit_pos; };
	void set_pos(ArrayPos pos) { unit_pos = pos; };

	int get_movement() const { return movement; };
	void set_move_path(Path path) { move_path = path; };
	void set_tentative_path(Path path) { tentative_path = path; };

	Path get_path() const { return move_path; };
	bool has_path() const { return not move_path.empty(); };


	Path move();
	void move_ai();
	Path next_turn();

private:
	//SkillList char_skills;
	int player_num;
	int movement;
	int moves_left;

	Path move_path;
	Path tentative_path;

	ArrayPos unit_pos;

	const float HEX_UNIT_RATIO_H = 0.75;
	const float HEX_UNIT_RATIO_W = 0.5;

};
#endif

