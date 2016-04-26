#include "Extra.h"

float clamp(const float & num, const float min, const float max)
{
	if (num > max) { return max; }
	if (num < min) { return min; }
	return num;
}
