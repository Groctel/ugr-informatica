#ifndef JPG_IMAGEN_HPP
#define JPG_IMAGEN_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "jpg_readwrite.hpp"

// clase 'Imagen'
//
// capa de abstracción sobre la clase jpg::JpegFile
// almacena los pixels de una imagen en memoria
// permite crearlos a partir de un archivo jpeg, y escribirlos a un jpeg

namespace jpg
{

typedef unsigned char color_pixel;

class Imagen
{
private:
	unsigned int altura   = 0;
	unsigned int anchura  = 0;
	color_pixel * pixeles = nullptr;

public:
	 Imagen (const std::string & ruta);
	~Imagen ();

	unsigned long   Altura  () const noexcept;
	unsigned long   Anchura () const noexcept;

	color_pixel * Pixeles () noexcept;
	color_pixel * Pixel   (unsigned int despl_hor, unsigned int despl_ver);

	void Guardar (const std::string & ruta);
};

} // namespace jpg

#endif
