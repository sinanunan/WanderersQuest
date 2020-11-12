#include"PathPoint.h"
#include"SouthWest.h"
#include"SouthEast.h"
#include"South.h"
#include"North.h"
#include"NorthEast.h"
#include"NorthWest.h"

std::unique_ptr<PathPoint> PathPoint::make_point(PathEnum dir)
{
	switch (dir)
	{
	case PathEnum::N:
		return std::make_unique<North>();
		break;
	case PathEnum::NE:
		return std::make_unique<NorthEast>();
		break;
	case PathEnum::SE:
		return std::make_unique<SouthEast>();
		break;
	case PathEnum::S:
		return std::make_unique<South>();
		break;
	case PathEnum::SW:
		return std::make_unique<SouthWest>();
		break;
	case PathEnum::NW:
		return std::make_unique<NorthWest>();
		break;
	default:
		break;
	}
}



PathEnum PathPoint::determine_dir(ArrayPos from, ArrayPos to)
{
	ArrayPos diff = from.dist(to);
	if (diff.r == 2)
		return PathEnum::S;
	else if (diff.r == -2)
		return PathEnum::N;
	else if (diff.r == 1) {
		if (diff.c == 1 or (diff.c == 0 and from.r % 2 == 0))
			return PathEnum::SE;
		else return PathEnum::SW;
	}
	else {
		if (diff.c == 1 or (diff.c == 0 and from.r % 2 == 0))
			return PathEnum::NE;
		else return PathEnum::NW;
	}
}


bool PathPoint::operator==(const PathEnum& dir) const
{
	return (type == dir);
}
