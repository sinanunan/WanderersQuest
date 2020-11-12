#ifndef PATH_POINT_H
#define PATH_POINT_H

#include "PathEnum.h"
#include "SDL.h"
#include <memory>
#include "CoorTypes.h"

class PathPoint
{
public:

	PathPoint(PathEnum dir) : type(dir) {};
	static std::unique_ptr<PathPoint> make_point(PathEnum dir);


	static PathEnum determine_dir(ArrayPos from, ArrayPos to);
	virtual void render(SDL_Rect& dest) {};
	PathEnum get_type() const { return type; };

	bool operator==(const PathEnum& dir) const;

		 
protected:

	const double PATH_HEX_RATIO = 0.5;
	PathEnum type;
};

#endif