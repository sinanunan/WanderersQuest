#include"PathPoint.h"
#include"SouthWest.h"
#include"SouthEast.h"
#include"East.h"
#include"West.h"
#include"NorthEast.h"
#include"NorthWest.h"

// factory function to make a point
std::unique_ptr<PathPoint> PathPoint::make_point(PathEnum dir)
{
	switch (dir)
	{
	case PathEnum::W:
		return std::make_unique<West>();
		break;
	case PathEnum::NE:
		return std::make_unique<NorthEast>();
		break;
	case PathEnum::SE:
		return std::make_unique<SouthEast>();
		break;
	case PathEnum::E:
		return std::make_unique<East>();
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


// Determines the direction of a movement between two array positions
PathEnum PathPoint::determine_dir(ArrayPos from, ArrayPos to)
{
	//std::cout << "from "<< from << "\nto" << to << "\n";
	ArrayPos diff = from.dist(to);
	if (diff.r == 0) {
		if (diff.c > 0) return PathEnum::E;
		else return PathEnum::W;
	}
	else if (diff.r == 1) {
		if (diff.c == 1 or (diff.c == 0 and from.r % 2 == 0))
			return PathEnum::SE;
		else return PathEnum::SW;
	}
	else {
		if (diff.c == 1 or (diff.c == 0 and from.r % 2 == 0)) {
			//std::cout << "NE\n";
			return PathEnum::NE;
		}
		else {
			//std::cout << "NW\n";
			return PathEnum::NW;
		}
	}
}


bool PathPoint::operator==(const PathEnum& dir) const
{
	return (type == dir);
}
