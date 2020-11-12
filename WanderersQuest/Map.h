#ifndef MAP_H
#define MAP_H
#include "Hex.h"
#include "SDL.h"
#include "UnitObject.h"
#include "TexManager.h"
#include "CoorTypes.h"
#include "Settlement.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include "Path.h"

class Map
{

public:
	// height and width in blocks
	Map(SDL_Renderer* game_renderer);
	~Map();

	void update();
	void pre_command();
	void render() const;

	void grow_around_pivot(ArrayPos pos, bool animation);
	ArrayPos find_cursor_hex(Coor cursor_coor);

	void create_city();

	void move_unit(UnitObject* unit, const Path passed_pos);
	Path find_path(ArrayPos pos1, ArrayPos pos2, bool click) const; 
	void clear_path(Path path);
	void set_path(Path path, bool click);

	void move_right(int extent);
	void move_left(int extent);
	void move_up(int extent);
	void move_down(int extent);


	
	void zoom_out(float multiplier);

	void assign_unit(UnitObject* unit);

	static Dimension map_dim; // in terms of row and column


	
private:
	
	SDL_Renderer* renderer;

	Hex** map_arr;
	Leftmost leftmost;

	// represents the number of hexes 
	Dimension window_dim;

	void initialize_map();

	Coor change;
	const int animation_speed = 5;
	void animate_pan();


	
	
	void check_leftmost_x();
	void check_leftmost_y();
	
	int dist_hor_tiles() const { return  int(hex_width  * 1.5); };
	int dist_ver_tiles() const { return  int(hex_height / 2  ); };
	int leftmost_min_x() const { return  int(-hex_width  / 4 ); };
	int leftmost_min_y() const { return  int(-hex_height / 2 ); };

	// the dimension of a single hex in the window
	// width is related to the height mathematically
	int width_to_height(const int width) const;
	const double width_height_ratio = 1.154;
	int hex_height;
	int hex_width;
};
#endif
