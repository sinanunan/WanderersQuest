#ifndef HEX_H
#define HEX_H

#include "UnitObject.h"
#include "CoorTypes.h"
#include "SDL.h"
#include "PathPoint.h"
#include "Settlement.h"
#include <memory>
#include <list>
#include <algorithm>

class Hex
{
public:
	Hex();

	void render(SDL_Rect& dest) const;
	void pre_command();

	void assign_unit(UnitObject* new_unit) { unit = new_unit; };
	UnitObject* get_unit() const { return unit; };
	bool has_unit() const { return unit != NULL; };
	void clear_unit() { unit = NULL; };

	void assign_move_path(std::unique_ptr<PathPoint> dir) { move_path.push_back(std::move(dir)); };
	void remove_path(PathEnum dir);
	void assign_tentative_path(std::unique_ptr<PathPoint> dir) { tentative_path = std::move(dir); };

	void assign_settlement(std::shared_ptr<Settlement> city) { settlement = city; };
	bool has_settlement() { return settlement != NULL; };

	static SDL_Renderer* renderer;
	static SDL_Texture* hex_tex;
	static SDL_Texture* tentative_tex;
	static SDL_Texture* path_tex;


private:

	UnitObject* unit;
	std::shared_ptr<Settlement> settlement;

	std::unique_ptr<PathPoint> tentative_path;
	std::list<std::unique_ptr<PathPoint>> move_path;

	const double HEX_CIRCLE_RATIO = 0.9;

};

#endif
