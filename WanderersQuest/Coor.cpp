#include "Coor.h"


std::ostream& operator<<(std::ostream& os, const Coor& coor)
{
	os << "Coor x:" << coor.x << "  y:" << coor.y;
	return os;
}

