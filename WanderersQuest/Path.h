#ifndef PATH_H
#define PATH_H

#include<queue>
#include"PathPoint.h"
#include"SouthWest.h"
#include"SouthEast.h"
#include"East.h"
#include"NorthWest.h"
#include"NorthEast.h"
#include"West.h"
#include"CoorTypes.h"

class Path
{
public:
	
	Path();
	Path(const ArrayPos starting_pos);
	ArrayPos operator[] (const int index) const; 
	
	std::unique_ptr<PathPoint> get_direction() const;
	PathEnum get_dir() const;


	unsigned size() const { return all_pos.size(); };
	bool empty() const { return all_pos.empty(); };
	void push(const ArrayPos pos) { all_pos.push_back(pos); };
	ArrayPos pop();

	ArrayPos get_start() const { return starting_pos; };


private:

	ArrayPos starting_pos;
	std::deque<ArrayPos> all_pos;
	
};

#endif

