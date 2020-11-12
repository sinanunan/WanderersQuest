#ifndef UNIT_OBJECT_H
#define UNIT_OBJECT_H
#include "SDL.h"
#include "SDL_image.h"
#include "TexManager.h"
#include "SkillList.h"
#include "CoorTypes.h"
#include <queue>
#include "Path.h"

// Class Decleration for a single unit

class UnitObject
{

public:
	UnitObject();
	UnitObject(ArrayPos starting_loc);
	
	static std::shared_ptr<UnitObject> generate_unit(ArrayPos start, int level);


	static SDL_Renderer* renderer; // TODO do it for all or not
	static SDL_Texture* unit_tex;
	
	void render(const SDL_Rect& hex) const;

	ArrayPos get_pos() const { return unit_pos; };
	void set_pos(ArrayPos pos) { unit_pos = pos; };

	int get_movement() const { return movement; };
	void set_move_path(std::shared_ptr<Path> path) { move_path = path; };
	void set_tentative_path(std::shared_ptr<Path> path) { tentative_path = path; };

	std::shared_ptr<Path> get_path() const { return move_path; };
	bool has_path() const { return (move_path != NULL); };

	void print_skills() { skills.print_list(); };
	SkillList* get_skills() { return &skills; };

	std::shared_ptr<Path> move();
	void move_ai();
	std::shared_ptr<Path> next_turn();

private:

	//SkillList char_skills;
	int player_num;
	int movement;
	int moves_left;

	std::shared_ptr<Path> move_path;
	std::shared_ptr<Path> tentative_path;

	SkillList skills;

	ArrayPos unit_pos;

	const float HEX_UNIT_RATIO_H = 0.75;
	const float HEX_UNIT_RATIO_W = 0.5;

};
#endif

