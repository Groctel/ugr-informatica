/** @file libig/textura.cpp
 */

#include "textura.hpp"

/**
 * @brief Constructor de la textura a partir de una imagen JPG.
 * @param ruta Ruta del fichero JPG.
 */

Textura :: Textura (const std::string & ruta, GLenum min, GLenum max) noexcept
:
	filtro_min (min),
	filtro_max (max)
{
	jpg::color_pixel * color;
	size_t indice_dato = 0;

	jpg::Imagen * imagen = new jpg::Imagen(ruta);

	altura  = imagen->Altura();
	anchura = imagen->Anchura();

	pixeles.resize(altura * anchura * 3);

	for (unsigned long i = 0; i < altura; i++)
	{
		for (unsigned long j = 0; j < anchura; j++)
		{
			color = imagen->Pixel(j, altura-i-1);

			pixeles[indice_dato++] = *color++;
			pixeles[indice_dato++] = *color++;
			pixeles[indice_dato++] = *color;
		}
	}

	delete imagen;
}

/**
 * @brief Activa la textura si aún no ha sido activada.
 */

void Textura :: Activar () noexcept
{
	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtro_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtro_max);

	if (id == (GLuint) nulltxr)
	{
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		/* glTexImage2D( */
		/* 	GL_TEXTURE_2D, */
		/* 	0, */
		/* 	GL_RGB, */
		/* 	anchura, */
		/* 	altura, */
		/* 	0, */
		/* 	GL_RGB, */
		/* 	GL_UNSIGNED_BYTE, */
		/* 	pixeles.data() */
		/* ); */
		gluBuild2DMipmaps(
			GL_TEXTURE_2D,
			GL_RGB,
			anchura,
			altura,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			pixeles.data()
		);
	}

	glBindTexture(GL_TEXTURE_2D, id);
}
