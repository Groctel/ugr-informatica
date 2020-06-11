#include <climits>
#include <iostream>
#include <vector>

int main (int argc, char ** argv) {
	const unsigned CALORIAS      = 313;
	const unsigned INFINITO      = UINT_MAX;
	const std::vector<unsigned> PLATOS = {75, 83, 19, 64, 21, 6, 33, 51, 22, 31, 51, 76, 40, 12, 45, 21, 84};

	unsigned consumidas          = 0;
	std::vector<unsigned> solucion;
	std::vector<std::vector<unsigned> > matriz_m;

	for (size_t i=0; i<=PLATOS.size(); i++) {
		matriz_m.emplace_back(std::vector<unsigned>());

		for (size_t j=0; j<=CALORIAS; j++)
			matriz_m[i].push_back(0);
	}

	for (size_t i=1; i<=CALORIAS; i++)
		matriz_m[0][i] = INFINITO;

	for (size_t i=1; i<=PLATOS.size(); i++) {
		unsigned actual,
		         consumible;

		for (size_t j=1; j<=CALORIAS; j++) {
			actual     = matriz_m[i-1][j];
			consumible = PLATOS[i-1];

			if (PLATOS[i-1] <= j) {
				consumible = matriz_m[i-1][j-PLATOS[i-1]];

				if (consumible < INFINITO)
					consumible += PLATOS[i-1];
			}

			matriz_m[i][j] = (consumible >= j) ? std::min(actual, consumible)
			                                   : INFINITO;
		}
	}

	for (size_t i=PLATOS.size(), j=CALORIAS; i>0 && j>0; i--) {
		if (matriz_m[i][j] != matriz_m[i-1][j]) {
			solucion.push_back(i-1);
			j -= PLATOS[i-1];
		}
	}

	for (unsigned n : solucion) {
		consumidas += PLATOS[n];
		std::cout << "Plato " << n+1 << ": " << PLATOS[n] << " calorías"
		          << std::endl;
	}

	std::cout << "Total consumido: " << consumidas << " calorías" << std::endl;

	return 0;
}
