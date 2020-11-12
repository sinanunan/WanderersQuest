#ifndef HEX_H
#define HEX_H

#include "UnitObject.h"
#include "CoorTypes.h"
#include "SDL.h"
#include "PathPoint.h"
#include "City.h"
#include <memory>
#include <list>
#include <algorithm>

class Hex
{
public:
	Hex();
	Hex(const Hex& copy);

	void render(SDL_Rect& dest) const;
	void pre_command();

	void assign_unit(std::shared_ptr<UnitObject>  new_unit) { unit = new_unit; };
	std::shared_ptr<UnitObject>  get_unit() const { return unit; };
	bool has_unit() const { return unit != NULL; };
	void clear_unit() { unit = NULL; };

	void assign_move_path(std::unique_ptr<PathPoint> dir) { move_path.push_back(std::move(dir)); };
	void remove_path(PathEnum dir);
	void assign_tentative_path(std::unique_ptr<PathPoint> dir) { tentative_path = std::move(dir); };

	void assign_city(std::shared_ptr<City> _city) { city = _city; };
	bool has_city() { return city != NULL; };
	std::shared_ptr<City> get_city() { return city; };

	static SDL_Renderer* renderer;
	static SDL_Texture* hex_tex;


private:

	std::shared_ptr<UnitObject>  unit;
	std::shared_ptr<City> city;

	std::unique_ptr<PathPoint> tentative_path;
	std::list<std::unique_ptr<PathPoint>> move_path;

	const double HEX_CIRCLE_RATIO = 0.9;

};

#endif
