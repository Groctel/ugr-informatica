#include "textura.hpp"

Textura :: Textura (const std::string & ruta) noexcept
{
	jpg::pixel * pixel;
	size_t indice_dato = 0;

	jpg::Imagen * imagen = new jpg::Imagen(ruta);

	altura  = imagen->Altura();
	anchura = imagen->Anchura();

	datos.resize(altura * anchura * 3);

	for (unsigned long i = 0; i < altura; i++)
	{
		for (unsigned long j = 0; j < anchura; j++)
		{
			pixel = imagen->Pixel(j, altura-i-1);

			datos[indice_dato++] = *pixel++;
			datos[indice_dato++] = *pixel++;
			datos[indice_dato++] = *pixel;
		}
	}

	id = ~0;

	delete imagen;
}

void Textura :: Activar () noexcept
{
	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT);
	/* glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); */

	if (id == (GLuint) ~0)
	{
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGB,
			anchura,
			altura,
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			datos.data()
		);
	}

	glBindTexture(GL_TEXTURE_2D, id);
}
