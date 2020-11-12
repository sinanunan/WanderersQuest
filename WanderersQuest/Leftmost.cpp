#include "Leftmost.h"

std::ostream& operator<<(std::ostream& os, const Leftmost& leftmost)
{
	os << "Leftmost r:" << leftmost.pos.r << "  c:" << leftmost.pos.c << "  x:" << leftmost.coor.x << "  y:" << leftmost.coor.y;
	return os;
}

