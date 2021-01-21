#include "jpg_imagen.hpp"

namespace jpg
{

/**
 * @brief Constructor con argumentos
 * @param ruta Ruta al archivo jpe?g a cargar en memoria.
 */

Imagen :: Imagen (const std::string & ruta)
{
	pixeles = JpegFile::JpegFileToRGB(ruta.c_str(), &anchura, &altura);

	if (pixeles == nullptr)
		throw std::runtime_error ("Error al cargar la imagen" + ruta + ".");
}

/**
 * @brief Destructor por defecto.
 */

Imagen :: ~Imagen ()
{
	if (pixeles != nullptr)
		delete [] pixeles;
}

/**
 * @brief Consultor al vector de píxeles de la imagen.
 */

pixel * Imagen :: Pixeles () noexcept
{
	return pixeles;
}

/**
 * @brief Consultor a un píxel concreto de la imagen.
 * @param despl_hor Posición horizontal del píxel consultado.
 * @param despl_ver Posición vertical del píxel consultado.
 */

pixel * Imagen :: Pixel (unsigned int despl_hor, unsigned int despl_ver)
{
	return pixeles + 3 * (anchura * despl_ver + despl_hor);
}

/**
 * @brief Consultor del tamaño vertical en píxeles de la imagen.
 */

unsigned long Imagen :: Altura () const noexcept
{
	return altura;
}

/**
 * @brief Consultor del tamaño horizontal en píxeles de la imagen.
 */

unsigned long Imagen :: Anchura () const noexcept
{
	return anchura;
}

/**
 * @brief Guarda la imagen en un fichero.
 * @param ruta Ruta al archivo jpe?g en el que guardar la imagen.
 */

void Imagen :: Guardar (const std::string & ruta)
{
	bool result = bool(JpegFile::RGBToJpegFile(
		ruta.c_str(),
		pixeles,
		anchura,
		altura,
		false, // Renderizar en escala de grises
		100    // Calidad de la imagen (1-100)
	));

	if (!result)
		throw std::runtime_error("Error al guardar " +  ruta + ".");
}

} // namespace jpg
