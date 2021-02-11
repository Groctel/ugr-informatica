/** @file global/global_functions.hpp
 */

#ifndef PRACTICAS_GLOBALS
#define PRACTICAS_GLOBALS

#include <cmath>
#include <iostream>

#define DEG_TO_RAD (M_PI / 180)
#define EPSILON 1e-5

/**
 * @brief Compara si dos float son iguales (si su diferencia es un cero gordo)
 */

inline bool FloatEq (const float & a, const float & b) noexcept
{
	return (fabs(a - b) < EPSILON);
}

/**
 * @brief Compara si un float vale cero (si es un cero gordo).
 */

inline bool FloatZ (const float & a) noexcept
{
	return (a < EPSILON);
}

/**
 * @brief Compara si dos float tienen el mismo signo.
 */

inline bool MismoSigno (const float & a, const float & b) noexcept
{
	return (a < 0) == (b < 0);
}

inline bool InvertirMatriz16 (const float origen[16], float destino[16])
{
	destino[0] =
		origen[5]  * origen[10] * origen[15] -
		origen[5]  * origen[11] * origen[14] -
		origen[9]  * origen[6]  * origen[15] +
		origen[9]  * origen[7]  * origen[14] +
		origen[13] * origen[6]  * origen[11] -
		origen[13] * origen[7]  * origen[10];

	destino[1] =
		-origen[1]  * origen[10] * origen[15] +
		 origen[1]  * origen[11] * origen[14] +
		 origen[9]  * origen[2]  * origen[15] -
		 origen[9]  * origen[3]  * origen[14] -
		 origen[13] * origen[2]  * origen[11] +
		 origen[13] * origen[3]  * origen[10];

	destino[2] =
		origen[1]  * origen[6] * origen[15] -
		origen[1]  * origen[7] * origen[14] -
		origen[5]  * origen[2] * origen[15] +
		origen[5]  * origen[3] * origen[14] +
		origen[13] * origen[2] * origen[7] -
		origen[13] * origen[3] * origen[6];

	destino[3] =
		-origen[1] * origen[6] * origen[11] +
		 origen[1] * origen[7] * origen[10] +
		 origen[5] * origen[2] * origen[11] -
		 origen[5] * origen[3] * origen[10] -
		 origen[9] * origen[2] * origen[7] +
		 origen[9] * origen[3] * origen[6];

	destino[4] =
		-origen[4]  * origen[10] * origen[15] +
		 origen[4]  * origen[11] * origen[14] +
		 origen[8]  * origen[6]  * origen[15] -
		 origen[8]  * origen[7]  * origen[14] -
		 origen[12] * origen[6]  * origen[11] +
		 origen[12] * origen[7]  * origen[10];

	destino[5] =
		origen[0]  * origen[10] * origen[15] -
		origen[0]  * origen[11] * origen[14] -
		origen[8]  * origen[2] * origen[15] +
		origen[8]  * origen[3] * origen[14] +
		origen[12] * origen[2] * origen[11] -
		origen[12] * origen[3] * origen[10];

	destino[6] =
		-origen[0]  * origen[6] * origen[15] +
		 origen[0]  * origen[7] * origen[14] +
		 origen[4]  * origen[2] * origen[15] -
		 origen[4]  * origen[3] * origen[14] -
		 origen[12] * origen[2] * origen[7] +
		 origen[12] * origen[3] * origen[6];

	destino[7] =
		origen[0] * origen[6] * origen[11] -
		origen[0] * origen[7] * origen[10] -
		origen[4] * origen[2] * origen[11] +
		origen[4] * origen[3] * origen[10] +
		origen[8] * origen[2] * origen[7] -
		origen[8] * origen[3] * origen[6];

	destino[8] =
		origen[4]  * origen[9]  * origen[15] -
		origen[4]  * origen[11] * origen[13] -
		origen[8]  * origen[5]  * origen[15] +
		origen[8]  * origen[7]  * origen[13] +
		origen[12] * origen[5]  * origen[11] -
		origen[12] * origen[7]  * origen[9];

	destino[9] =
		-origen[0]  * origen[9]  * origen[15] +
		 origen[0]  * origen[11] * origen[13] +
		 origen[8]  * origen[1]  * origen[15] -
		 origen[8]  * origen[3]  * origen[13] -
		 origen[12] * origen[1]  * origen[11] +
		 origen[12] * origen[3]  * origen[9];

	destino[10] =
		origen[0]  * origen[5] * origen[15] -
		origen[0]  * origen[7] * origen[13] -
		origen[4]  * origen[1] * origen[15] +
		origen[4]  * origen[3] * origen[13] +
		origen[12] * origen[1] * origen[7] -
		origen[12] * origen[3] * origen[5];

	destino[11] =
		-origen[0] * origen[5] * origen[11] +
		 origen[0] * origen[7] * origen[9] +
		 origen[4] * origen[1] * origen[11] -
		 origen[4] * origen[3] * origen[9] -
		 origen[8] * origen[1] * origen[7] +
		 origen[8] * origen[3] * origen[5];

	destino[12] =
		-origen[4]  * origen[9]  * origen[14] +
		 origen[4]  * origen[10] * origen[13] +
		 origen[8]  * origen[5]  * origen[14] -
		 origen[8]  * origen[6]  * origen[13] -
		 origen[12] * origen[5]  * origen[10] +
		 origen[12] * origen[6]  * origen[9];

	destino[13] =
		origen[0]  * origen[9] * origen[14] -
		origen[0]  * origen[10] * origen[13] -
		origen[8]  * origen[1] * origen[14] +
		origen[8]  * origen[2] * origen[13] +
		origen[12] * origen[1] * origen[10] -
		origen[12] * origen[2] * origen[9];

	destino[14] =
		-origen[0]  * origen[5] * origen[14] +
		 origen[0]  * origen[6] * origen[13] +
		 origen[4]  * origen[1] * origen[14] -
		 origen[4]  * origen[2] * origen[13] -
		 origen[12] * origen[1] * origen[6] +
		 origen[12] * origen[2] * origen[5];

	destino[15] =
		origen[0] * origen[5] * origen[10] -
		origen[0] * origen[6] * origen[9] -
		origen[4] * origen[1] * origen[10] +
		origen[4] * origen[2] * origen[9] +
		origen[8] * origen[1] * origen[6] -
		origen[8] * origen[2] * origen[5];

	float determinante =
		origen[0] * destino[0] +
		origen[1] * destino[4] +
		origen[2] * destino[8] +
		origen[3] * destino[12];

	bool invertible = (!FloatZ(determinante));

	if (invertible)
	{
		determinante = 1.0 / determinante;

		destino[0]  *= determinante;
		destino[1]  *= determinante;
		destino[2]  *= determinante;
		destino[3]  *= determinante;
		destino[4]  *= determinante;
		destino[5]  *= determinante;
		destino[6]  *= determinante;
		destino[7]  *= determinante;
		destino[8]  *= determinante;
		destino[9]  *= determinante;
		destino[10] *= determinante;
		destino[11] *= determinante;
		destino[12] *= determinante;
		destino[13] *= determinante;
		destino[14] *= determinante;
		destino[15] *= determinante;
	}

	return invertible;
}

#endif
