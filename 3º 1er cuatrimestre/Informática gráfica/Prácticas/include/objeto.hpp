#ifndef PRACTICAS_OBJETO
#define PRACTICAS_OBJETO

#include <string>
#include "malla.hpp"

class Objeto
{
private:
	Malla3D * modelo;
	std::string nombre;
	float escalado[3]   = {1,1,1};
	float rotacion[4]   = {0,0,0,0};
	float traslacion[3] = {0,0,0};

public:
	Objeto () noexcept;
	Objeto (Malla3D * nuevo_modelo, std::string nuevo_nombre) noexcept;
	Objeto (const Objeto & otro) noexcept;
	~Objeto () noexcept;

	Malla3D     * Modelo     () const noexcept;
	std::string   Nombre     () const noexcept;
	const float * Escalado   () const noexcept;
	const float * Rotacion   () const noexcept;
	const float * Traslacion () const noexcept;

	bool operator < (const Objeto & otro) const noexcept;
	Objeto * operator = (const Objeto & otro) noexcept;

	void Escalar (
		const float x, const float y, const float z
	) noexcept;

	void Rotar (
		const float angulo, const float x, const float y, const float z
	) noexcept;

	void Trasladar (
		const float x, const float y, const float z
	) noexcept;

	void LiberarMalla () noexcept;
};

#endif
