/** @file rectangulo.hpp
  */

/** @class Rectangulo
  * @brief Rectángulo de características arbitrarias
  *
  * @var unsigned altura   Número de bloques de elevación sobre la base
  * @var unsigned anchura  Número de bloques que se extiende el rectángulo hacia valores positivos del eje `x`
  * @var unsigned posicion Índice del bloque de valores positivos del eje `x` en el que comienza el rectángulo
  *
  * No se restringen las características de los rectángulos, de forma que podría haber varios rectángulos iguales en una misma instancia del problema.
  */

class Rectangulo {
private:
	unsigned altura,
	         anchura,
	         posicion;
public:
	Rectangulo ();
	Rectangulo (unsigned alt, unsigned anch, unsigned pos);

	static const unsigned MAX_ALTURA   = 20,
	                      MAX_ANCHURA  = 20,
	                      MAX_POSICION = 20;

	unsigned Altura   () const;
	unsigned Anchura  () const;
	unsigned Posicion () const;

	bool SetAltura      (unsigned alt);
	bool SetAnchura     (unsigned anch);
	bool SetPosicion    (unsigned pos);
	bool SetDimensiones (unsigned alt, unsigned anch, unsigned pos);
};
