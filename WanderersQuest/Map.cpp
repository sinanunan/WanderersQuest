#include "Map.h"

Dimension Map::map_dim = Dimension();

Map::Map(SDL_Renderer* game_renderer):
	renderer(game_renderer)
{
	initialize_map();
	
	change.x = 0;
	change.y = 0;
	
}

Map::~Map()
{
	for (int i = 0; i < map_dim.h; i++) {
		delete[] map_arr[i];
	}
	delete[] map_arr;
}
void Map::initialize_map() {
	
	window_dim.h = 900;
	window_dim.w = 1800;
	map_dim.h = 10;
	map_dim.w = 10;
	// map_dim = input_dim;

	//hex_height = 200;
	//height_to_width();
	hex_width = 232;
	hex_height = width_to_height(hex_width);

	leftmost.coor.x = leftmost_min_x();
	leftmost.coor.y = leftmost_min_y();
	//leftmost_y = int(-hex_height);
	leftmost.pos.c = 0; // TODO change to starting location
	leftmost.pos.r = 0;

	map_arr = new Hex *[map_dim.h];
	for (int i = 0; i < map_dim.h; i++) {
		map_arr[i] = new Hex[map_dim.h];
	}

	//map_arr[2][2].assign_unit(unit, 2, 2);
	//map_arr[2][0].assign_unit(unit, 2, 0);
}

void Map::update()
{
	animate_pan();
}

void Map::pre_command()
{
	for (int r = 0; r < map_dim.h; r++) {
		for (int c = 0; c < map_dim.w; c++) {
			map_arr[r][c].pre_command();
		}
	}
}

void Map::animate_pan()
{
	if (change.x)
	{
		if (change.x > 0) {
			if (change.x < animation_speed) {
				move_left(change.x);
				change.x = 0;
			}
			else {
				move_left(animation_speed);
				change.x -= animation_speed;
			}
		}
		else {
			if (abs(change.x) < animation_speed) {
				move_right(abs(change.x));
				change.x = 0;
			}
			else {
				move_right(animation_speed);
				change.x += animation_speed;
			}
		}
	}

	if (change.y)
	{
		if (change.y > 0) {
			if (change.y < animation_speed) {
				move_up(change.y);
				change.y = 0;
			}
			else {
				move_up(animation_speed);
				change.y -= animation_speed;
			}
		}
		else {
			if (abs(change.y) < animation_speed) {
				move_down(abs(change.y));
				change.y = 0;
			}
			else {
				move_down(animation_speed);
				change.y += animation_speed;
			}
		}
	}
}

void Map::render() const
{
	
	SDL_Rect dest;
	dest.h = int(hex_height);
	dest.w = int(hex_width);
	dest.x = leftmost.coor.x;
	dest.y = leftmost.coor.y;

	
	ArrayPos map_dest(leftmost.pos.r, leftmost.pos.c);

	bool alternate = false;
	while (dest.y < window_dim.h) {
		int start_x = dest.x; // since hexes alternate every row, the start location of the previous line is stored
		map_dest.c = leftmost.pos.c;
		while (dest.x < window_dim.w) {
			map_arr[map_dest.r][map_dest.c].render(dest);
			
			dest.x += dist_hor_tiles();
			map_dest.c = map_dest.next_tile_c();
			
		}

		if (alternate) dest.x = start_x - dist_hor_tiles() / 2;
		else dest.x = start_x + dist_hor_tiles() / 2;
		alternate = not alternate;
		
		dest.y += dist_ver_tiles();
		map_dest.r = map_dest.next_tile_r();
	}
	

}

void Map::grow_around_pivot(ArrayPos pos, bool animation)
{

	// getting desired x and y locations of the pivot
	Coor desired;
	desired.x = int((window_dim.w - hex_width ) / 2);
	desired.y = int((window_dim.h - hex_height) / 2);
	
	Coor dist;
	dist.x = desired.x - leftmost_min_x();
	dist.y = desired.y - leftmost_min_y();
	
	// calculating the number of tiles between the leftmost tile and the pivot
	Coor req_tile;
	req_tile.x = ceil(double(dist.x) / double(dist_hor_tiles()));
	req_tile.y = ceil(double(dist.y) / (2 * double(dist_ver_tiles())));
	
	// calculating the new leftmost coordinate and hex
	Leftmost new_leftmost;
	new_leftmost.coor.x = desired.x - req_tile.x * dist_hor_tiles();
	new_leftmost.coor.y = desired.y - req_tile.y * 2 * dist_ver_tiles();
	new_leftmost.pos.r = pos.prev_tile_r(2 * req_tile.y);
	new_leftmost.pos.c = pos.prev_tile_c(req_tile.x);


	// if the row is even, we make the leftmost up-left tile (leftmost is always even)
	if (pos.r % 2 == 1) {
		new_leftmost.coor.x -= dist_hor_tiles() / 2;
		new_leftmost.coor.y -= dist_ver_tiles();
		new_leftmost.pos.r = new_leftmost.pos.prev_tile_r();
	}
	if (animation) {
		change.x = leftmost.pos.dist_cols(new_leftmost.pos) * dist_hor_tiles() - (new_leftmost.coor.x - leftmost.coor.x);
		change.y = leftmost.pos.dist_rows(new_leftmost.pos) * dist_ver_tiles() - (new_leftmost.coor.y - leftmost.coor.y);
	} 
	else {
		leftmost = new_leftmost;
	}
	
}


// TODO also assigns paths to hexes
Path Map::find_path(ArrayPos unit_pos, ArrayPos dest, bool click) const
{
	ArrayPos temp = unit_pos;
	Path path(unit_pos);

	int moves = 0;

	while (temp != dest) {

		int col_dist = temp.dist_cols(dest);
		int row_dist = temp.dist_rows(dest);
		if (col_dist == 0 and abs(row_dist) != 1) {
			if (row_dist > 0) {
				temp.r = temp.next_tile_r(2);
			}
			else {
				temp.r = temp.prev_tile_r(2);
			}
		}
		else {
			if (col_dist > 0) {
				if (temp.r % 2 == 1) {
					temp.c = temp.next_tile_c();
				}
			}
			else if (col_dist < 0) {
				if (temp.r % 2 == 0) {
					temp.c = temp.prev_tile_c();
				}
			}
			if (row_dist > 0) {
				temp.r = temp.next_tile_r();
			}
			else {
				temp.r = temp.prev_tile_r();
			}
		}
		path.push(temp);
	}
	return path;
}

void Map::set_path(Path path, bool click)
{
	if (path.empty()) return;

	std::unique_ptr<PathPoint> ptr;

	ArrayPos temp = path.get_start();

	while (not path.empty()) {
		
		ptr = path.get_direction();
		
		if (click) map_arr[temp.r][temp.c].assign_move_path(std::move(ptr));
		else  map_arr[temp.r][temp.c].assign_tentative_path(std::move(ptr));

		temp = path.pop();

		
	}

}


void Map::clear_path(Path path)
{
	ArrayPos temp = path.get_start();
	PathEnum dir;

	while (not path.empty()) {
		dir = path.get_dir();
		map_arr[temp.r][temp.c].remove_path(dir);
		temp = path.pop();
	}
}



ArrayPos Map::find_cursor_hex(Coor cursor_coor)
{
	if (cursor_coor.x > window_dim.w or cursor_coor.x < 0 or 
	    cursor_coor.y > window_dim.h or cursor_coor.y < 0) return ArrayPos(window_dim.h, window_dim.w);

	Coor dist;
	dist.x = cursor_coor.x - leftmost.coor.x;
	dist.y = cursor_coor.y - leftmost.coor.y;

	Dimension tile_dist;
	tile_dist.w = dist.x / dist_hor_tiles();
	tile_dist.h = dist.y / (dist_ver_tiles() * 2);
	tile_dist.h *= 2;
	
	Coor extra_dist;
	extra_dist.x = dist.x % dist_hor_tiles();
	extra_dist.y = dist.y % (dist_ver_tiles() * 2);
	if (extra_dist.x < hex_width / 4) {
		int upleft_expected_y = (hex_height / 2) - 2 * width_to_height(extra_dist.x);
		int downleft_expected_y = hex_height / 2 + 2 * width_to_height(extra_dist.x);
			if (extra_dist.y < upleft_expected_y) {
				tile_dist.w--;
				tile_dist.h--;
			}
			else if (extra_dist.y > downleft_expected_y) {
				tile_dist.w--;
				tile_dist.h++;
			}
	} 
	else if (extra_dist.x > 3 * hex_width / 4) {
		int x_offset = hex_width - extra_dist.x;
		if (x_offset < 0) {
			if (extra_dist.y > hex_height / 2) tile_dist.h++;
			else tile_dist.h--;
		} 
		else {
			int upright_expected_y = (hex_height / 2) - 2 * width_to_height(x_offset);
			int downright_expected_y = hex_height / 2 + 2 * width_to_height(x_offset);

			if (extra_dist.y < upright_expected_y) {
				tile_dist.h--;
			}
			else if (extra_dist.y > downright_expected_y) {
				tile_dist.h++;
			}
		}
	}

	ArrayPos cursor_pos;
	cursor_pos.r = leftmost.pos.next_tile_r(tile_dist.h);
	cursor_pos.c = leftmost.pos.next_tile_c(tile_dist.w);
	
	return cursor_pos;
}

void Map::move_right(const int extent)
{
	leftmost.coor.x += extent;
	check_leftmost_x();
}

void Map::move_left(const int extent)
{
	leftmost.coor.x -= extent;
	check_leftmost_x();
}

void Map::move_down(const int extent)
{
	leftmost.coor.y += extent;
	check_leftmost_y();
}


void Map::move_up(const int extent)
{
	leftmost.coor.y -= extent;
	check_leftmost_y();
}

void Map::check_leftmost_x()
{
	if (leftmost.coor.x > leftmost_min_x()) {
		leftmost.coor.x -= dist_hor_tiles();
		leftmost.pos.c = leftmost.pos.prev_tile_c();
	}
	if (leftmost.coor.x < leftmost_min_x() - dist_hor_tiles()) {
		leftmost.coor.x += dist_hor_tiles();
		leftmost.pos.c = leftmost.pos.next_tile_c();
	}
}

void Map::check_leftmost_y()
{
	if (leftmost.coor.y > leftmost_min_y()) {
		leftmost.coor.y -= 2 * dist_ver_tiles();
		leftmost.pos.r = leftmost.pos.prev_tile_r( 2);
	}
	if(leftmost.coor.y < leftmost_min_y() - 2 * dist_ver_tiles()) {
		leftmost.coor.y += 2 * dist_ver_tiles();
		leftmost.pos.r = leftmost.pos.next_tile_r
		(2);
	}
}



void Map::zoom_out(float multiplier) // TODO write function
{
	int old_height = hex_height;
	int old_width = hex_width;
	hex_height *= multiplier;
	hex_width *= multiplier;
	////int hex_w_window = 
	//int hex_h_window = 

}

int Map::width_to_height(const int width) const
{
	int temp_height = double(width) / width_height_ratio;

	if (temp_height % 2 == 1) temp_height++;

	return temp_height;
}


void Map::assign_unit(UnitObject* unit)
{
	ArrayPos unit_pos = unit->get_pos();
	map_arr[unit_pos.r][unit_pos.c].assign_unit(unit);


}

void Map::move_unit(UnitObject* unit, const Path passed_pos)
{
	if (passed_pos.empty()) return;
	
	clear_path(passed_pos);

	// moves the unit
	bool collision;ArrayPos unit_pos = unit->get_pos();
	map_arr[unit_pos.r][unit_pos.c].assign_unit(unit);
	

	ArrayPos old_pos = passed_pos.get_start();
	map_arr[old_pos.r][old_pos.c].clear_unit();
	
}

void Map::create_city()
{
	std::shared_ptr<Settlement> city = std::make_shared<Settlement>();
	map_arr[0][0].assign_settlement(city);
	
}
