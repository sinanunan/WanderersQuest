#ifndef DIMENSION_H
#define DIMENSION_H

#include <iostream>
#include "PathEnum.h"

// Dimension struct used to represent the dimensions of a hexmap

struct Dimension
{
	int w;
	int h;
	Dimension(int w, int h) {
		this->h = h;
		this->w = w;
	}
	Dimension() { h = 0; w = 0; };


	friend std::ostream& operator<<(std::ostream& os, const Dimension& dim);

};
#endif

