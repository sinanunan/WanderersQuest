#ifndef ARRAY_POS_H
#define ARRAY_POS_H

#include <iostream>
#include "PathEnum.h"
#include "Dimension.h"

struct ArrayPos
{
	int r;
	int c;
	ArrayPos(int r, int c) {
		this->r = r;
		this->c = c;
	}
	ArrayPos() { r = 0; c = 0; };
	
	friend std::ostream& operator<<(std::ostream& os, const ArrayPos& pos);

	friend bool operator!=(const ArrayPos& left, const ArrayPos& right);
	friend bool operator==(const ArrayPos& left, const ArrayPos& right);

	friend ArrayPos operator-(const ArrayPos& left, const ArrayPos& right);

	int next_tile_c(const int extent = 1) const;
	int next_tile_r(const int extent = 1) const;
	int prev_tile_c(const int extent = 1) const;
	int prev_tile_r(const int extent = 1) const;

	ArrayPos dist(const ArrayPos to) const;
	int dist_cols(const ArrayPos to) const;
	int dist_rows(const ArrayPos to) const;





};
#endif