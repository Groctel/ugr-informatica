/** @file libig/enum.hpp
 */

#ifndef PRACTICAS_ENUM
#define PRACTICAS_ENUM

/** @enum Dibujo
 * @brief Modos de envío de las órdenes de dibujo a la GPU.
 */

enum Dibujo
{
	Diferido,
	Inmediato
};

/** @enum EjeRotacion
 * @brief Eje alrededor del cual se ha de rotar un ObjRevolucion.
 */

enum EjeRotacion
{
	EjeX,
	EjeY,
	EjeZ
};

/** @enum EstadoRaton
 * @brief Operación que el ratón del usuario está realizando en cada momento.
 */

enum EstadoRaton
{
	MovimientoExaminar,
	Movimiento1raPersona,
	Reposo
};

/** @enum Menu
 * @brief Estado actual del menú de control de la escena.
 */

enum Menu
{
	Inactivo,
	SeleccionAnimacion,
	SeleccionCamara,
	SeleccionDibujado,
	SeleccionLuces,
	SeleccionMovimiento,
	SeleccionObjeto,
	SeleccionVisualizacion,
};

/** @enum ModoTextura
 * @brief Algoritmo a seguir a la hora de aplicar la textura a un objeto.
 */

enum ModoTextura
{
	Cilindrica,
	Esferica,
	Plana
};

/** @enum PropiedadesPLY
 * @brief Distintas propiedades declarables en la cabecera de un PLY.
 */

enum PropiedadesPLY
{
	x,
	y,
	z,
	nx,
	ny,
	nz,
	s,
	t
};

/** @enum Tapas
 * @brief Cantidad de tapas con las que crear un ObjRevolucion.
 */

enum Tapas
{
	Ninguna  = 0,
	Superior = 1,
	Inferior = 1,
	Ambas    = 2
};

/** @enum TipoCamara
 * @brief Formas de gestionar la cámara de cara a los cálculos.
 */

enum TipoCamara
{
	Ortogonal,
	Perspectiva
};

/** @enum Visualizacion
 * @brief Modos de visualización de los modelos.
 */

enum Visualizacion
{
	Ajedrez     = 0,
	Lineas      = 1,
	Puntos      = 2,
	Solido      = 3,
	Iluminacion = 4,
	Texturas    = 5,
};

#endif
