#include "cono.hpp"

Cono :: Cono (size_t iteraciones, float altura, float radio, Tapas tapas)
{
	perfil = {
		{radio, 0, 0},
		{0, altura, 0}
	};
	Revolucionar(iteraciones, tapas);
}
