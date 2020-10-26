#ifndef PRACTICAS_PLY
#define PRACTICAS_PLY

#include <fstream>
#include <iostream>
#include <regex>
#include <stdexcept>
#include "motor.hpp"
#include "malla.hpp"

class PLY : public Malla3D
{
private:
	template <class T>
	inline void Redimensionar (
		const std::string & linea,
		std::vector<T> & tabla
	) noexcept;

	void InterpretarCabecera (std::ifstream & fi);
	void InterpretarVertices (std::ifstream & fi) noexcept;
	void InterpretarCaras    (std::ifstream & fi) noexcept;

public:
	PLY (const std::string & ruta);
};

#endif
