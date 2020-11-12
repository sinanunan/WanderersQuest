#ifndef LEFTMOST_H
#define LEFTMOST_H
#include <iostream>
#include "Coor.h"
#include "ArrayPos.h"

struct Leftmost
{
	ArrayPos pos;
	Coor coor;

	friend std::ostream& operator<<(std::ostream& os, const Leftmost& leftmost);


};
#endif