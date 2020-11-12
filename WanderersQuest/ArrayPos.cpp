#include "ArrayPos.h"
#include "Map.h"


std::ostream& operator<<(std::ostream& os, const ArrayPos& pos)
{
	os << "ArrayPos r:" << pos.r << "  c:" << pos.c;
	return os;
}

bool operator==(const ArrayPos& left, const ArrayPos& right)
{
	return (left.c == right.c and left.r == right.r);
}


bool operator!=(const ArrayPos& left, const ArrayPos& right)
{
	return not (left == right);
}


ArrayPos operator-(const ArrayPos& left, const ArrayPos& right)
{
	ArrayPos to_return;
	to_return.r = left.r - right.r;
	to_return.c = left.c - right.c;
	return to_return;
}


int ArrayPos::next_tile_c(const int extent) const // TODO make extent potional int extent = 1
{
	return (c + extent) % Map::map_dim.w;
}

int ArrayPos::next_tile_r(const int extent) const
{
	return (r + extent) % Map::map_dim.h;
}
int ArrayPos::prev_tile_c(const int extent) const
{
	int temp_c = c;
	temp_c -= extent;
	if (temp_c < 0) temp_c += Map::map_dim.h;

	return temp_c;
}

int ArrayPos::prev_tile_r(const int extent) const
{
	int temp_r = r;
	temp_r -= extent;
	if (temp_r < 0) temp_r += Map::map_dim.h;
	return temp_r;
}



ArrayPos ArrayPos::dist(const ArrayPos to) const
{
	ArrayPos dist;
	dist.c = dist_cols(to);
	dist.r = dist_rows(to);
	return dist;
}



int ArrayPos::dist_cols(const ArrayPos to) const
{
	int dist = to.c - c;
	int map_w = Map::map_dim.w;


	if (to.c > c) {
		if (dist < abs(dist - map_w)) return dist;
		else return dist - map_w;
	}
	else {
		if (abs(dist) < abs(dist + map_w)) return dist;
		else return dist + map_w;
	}
}

int ArrayPos::dist_rows(const ArrayPos to) const
{
	int dist = to.r- r;
	int map_h = Map::map_dim.h;

	if (to.r > r) {
		if (dist < abs(dist - map_h)) return dist;
		else return dist - map_h;
	}
	else {
		if (abs(dist) < abs(dist + map_h)) return dist;
		else return dist + map_h;
	}
}
