#include "globals.hpp"

bool FloatEq (const float & a, const float & b) noexcept
{
	return abs(a - b) < std::numeric_limits<double>::epsilon();
}

bool FloatZ (const float & a) noexcept
{
	return a < std::numeric_limits<double>::epsilon();
}

bool MismoSigno (const float & a, const float & b) noexcept
{
	return (a < 0) == (b < 0);
}
