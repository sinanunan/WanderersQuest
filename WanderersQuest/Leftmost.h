#ifndef LEFTMOST_H
#define LEFTMOST_H
#include <iostream>
#include "Coor.h"
#include "ArrayPos.h"

// Leftmost object representing the leftmost even hex on the screen

struct Leftmost
{
	ArrayPos pos;
	Coor coor;

	friend std::ostream& operator<<(std::ostream& os, const Leftmost& leftmost);


};
#endif