/*
 * AUTORES:
 * - Clara Romero Lara
 * - Atanasio José Rubio Gil
 */

/** @file include/letra.hpp
  */

#ifndef LETRA
#define LETRA

/** @class Letra
  * @brief Alamcenamiento estadístico de cada una de las letras del diccionario
  *
  * @var grafema
  * @var frecuencia Frecuencia absoluta con la que aparece la letra
  */

class Letra {
private:
	char     grafema;
	unsigned frecuencia;

public:
	Letra ();
	Letra (char g, unsigned f);
	Letra (const Letra & otra);

	char     Grafema    () const;
	unsigned Frecuencia () const;

	void NuevoGrafema    (const char g);
	void NuevaFrecuencia (const unsigned f);

	Letra &    operator =  (const Letra & otra);
	bool       operator == (const Letra & otra) const;
	bool       operator != (const Letra & otra) const;
	bool       operator <  (const Letra & otra) const;
	bool       operator >  (const Letra & otra) const;
	bool       operator <= (const Letra & otra) const;
	bool       operator >= (const Letra & otra) const;
	unsigned & operator ++ ();
	unsigned & operator -- ();
};

#endif
