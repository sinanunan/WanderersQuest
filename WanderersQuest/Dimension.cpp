#include "Dimension.h"

std::ostream& operator<<(std::ostream& os, const Dimension& dim)
{
	os << "Dimension w:" << dim.w << "  h:" << dim.h;
	return os;
}