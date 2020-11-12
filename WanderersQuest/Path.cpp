#include "Path.h"

Path::Path()
{

}

Path::Path(const ArrayPos starting_pos) : 
	starting_pos(starting_pos)
{

}

ArrayPos Path::operator[] (const int index) const
{
	if (index >= all_pos.size()) {
		exit(1);
	}

	return all_pos[index];
}

ArrayPos Path::pop()
{
	starting_pos = all_pos.front(); 
	all_pos.pop_front(); 
	return starting_pos; 
}


std::unique_ptr<PathPoint> Path::get_direction() const
{
	PathEnum type = PathPoint::determine_dir(starting_pos, all_pos.front());
	return PathPoint::make_point(type);
}

PathEnum Path::get_dir() const
{
	return PathPoint::determine_dir(starting_pos, all_pos.front());
}
