#ifndef PATH_POINT_H
#define PATH_POINT_H

#include "PathEnum.h"
#include "SDL.h"
#include <memory>
#include "CoorTypes.h"

// Superclass pathpoint used to determine and assign arrows to directions

class PathPoint
{
public:

	static std::unique_ptr<PathPoint> make_point(PathEnum dir);

	static PathEnum determine_dir(ArrayPos from, ArrayPos to);
	
	virtual void render(SDL_Rect& dest) = 0;
	
	PathEnum get_type() const { return type; };

	bool operator==(const PathEnum& dir) const;

		 
protected:

	PathPoint(PathEnum dir) : type(dir) {};
	const double PATH_HEX_RATIO = 0.5;
	PathEnum type;
};

#endif