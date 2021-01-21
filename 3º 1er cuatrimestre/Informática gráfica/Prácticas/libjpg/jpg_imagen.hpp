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

class Imagen
{
private:
	unsigned char * pixeles = nullptr;
	unsigned int altura     = 0;
	unsigned int anchura    = 0;

public:
	 Imagen (const std::string & ruta);
	~Imagen ();

	unsigned char * Pixeles () noexcept;
	unsigned char * Pixel   (unsigned int despl_hor, unsigned int despl_ver);
	unsigned long   Altura  () const noexcept;
	unsigned long   Anchura () const noexcept;

	void Guardar (const std::string & ruta);
};

} // namespace jpg

#endif
