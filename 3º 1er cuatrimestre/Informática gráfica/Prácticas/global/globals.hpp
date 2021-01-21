/**
 * @file global/global_functions.hpp
 */

#ifndef PRACTICAS_GLOBALS
#define PRACTICAS_GLOBALS

#include <cmath>
#include <limits>

/**
 * @brief Compara si dos float son iguales (si su diferencia es un cero gordo)
 */

inline bool FloatEq (const float & a, const float & b) noexcept
{
	return abs(a - b) < std::numeric_limits<double>::epsilon();
}

/**
 * @brief Compara si un float vale cero (si es un cero gordo).
 */

inline bool FloatZ (const float & a) noexcept
{
	return a < std::numeric_limits<double>::epsilon();
}

/**
 * @brief Compara si dos float tienen el mismo signo.
 */

inline bool MismoSigno (const float & a, const float & b) noexcept
{
	return (a < 0) == (b < 0);
}

#endif
