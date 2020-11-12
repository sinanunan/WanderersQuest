#ifndef COOR_H
#define COOR_H

#include <iostream>
#include "PathEnum.h"

// Represents the coordinate in a window

struct Coor
{
	int x;
	int y;

	Coor(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Coor() { x = 0; y = 0; };


	friend std::ostream& operator<<(std::ostream& os, const Coor& coor);

};
#endif