#include "utils.hpp"

int DivisionEntera (int dividendo, int divisor) {
	int dif = dividendo - divisor;

	return (dif < 0) ? 0
	                 : 1 + DivisionEntera(dif, divisor);
}

int RestoDivision (int dividendo, int divisor) {
	return (dividendo - divisor < 0) ? dividendo
	                                 : RestoDivision(dividendo-divisor, divisor);
}
