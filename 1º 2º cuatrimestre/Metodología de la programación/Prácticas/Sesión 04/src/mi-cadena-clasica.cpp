/** @file mi_cadena_clasica.cpp
  */

#include <cctype>
#include "mi-cadena-clasica.hpp"

/** @fn bool Palindromo (const char * cadena)
  * @brief Comprueba si una cadena es un palíndromo
  *
  * @param cadena Cadena de caracteres con terminación nula
  *
  * @return Condición de palíndromo de la cadena
  *
  * Colocamos el puntero en el primer carácter de la cadena y el puntero
  * reverso, en el último. Mientras los caracteres a los que apuntan sean
  * iguales y no se hayan cruzaado, aumentamos el primero y reducimos el
  * segundo. Sabemos que la cadena es un palíndromo si los punteros se han
  * cruzaado.
  */

bool Palindromo (const char * cadena) {
	const char * p  = cadena,
	           * pr = cadena + LongitudCadena(cadena) - 1;

	while (*p == *pr && p < pr) {
		p++;
		pr--;
	}

	return p >= pr;
}

/** @fn int CompararCadenas (const char * una, const char * otra)
  * @brief Comparador a tres sentidos de dos cadenas (operador <=>)
  *
  * @param una Primera cadena con terminación nula a comparar
  * @param otra Segunda cadena con terminación nula a comparar
  *
  * @return Diferencia entre ambas cadenas (una-otra)
  *
  * Definimos la diferencia entre dos cadenas como la diferencia entre el primer
  * carácter distinto de las mismas (a<b<c), de forma que puedan ordenarse
  * lexicográficamente. Avanzamos hasta que encontremos un carácter distinto o
  * un terminador. En el primer caso, la diferencia es la resta del carácter de
  * la primera cadena con el carácter de la otra. En caso de que este bucle
  * acabde con diferencia 0, es posible que se haya llegado a un terminador en
  * alguna de las cadenas (o en ambas si son iguales). En este caso, la
  * diferencia es el mayor de los caracteres a los que apunten los punteros,
  * teniendo en cuenta que el terminador vale exactamente 0.
  */

int CompararCadenas (const char * una, const char * otra) {
	int diferencia = 0;

	while (diferencia == 0 && *una != '\0' && *otra != '\0')
		diferencia = *(una++) - *(otra++);

	if (diferencia == 0)
		diferencia = MAX(*una, *otra);

	return diferencia;
}

/** @fn int LongitudCadena (const char * cadena)
  * @brief Calcula el número de caracteres de una cadena sin tener en cuenta el
  * carácter terminador
  *
  * @param cadena Cadena de caracteres con terminación nula
  *
  * @return Longitud de la cadena
  *
  * Aunque una implementación válida habría sido definir un puntero al inicio de
  * la cadena y hacerlo avanzar hasta encontrar el temrinador incrementando la
  * longitud de la cadena, aprovechamos este dato, que es el que vamos a
  * devolver. Como podemos desreferenciar la cadena en cualquier punto del
  * vector (`*(cadena + i)`), utilizamos la `longitud` para avanzar por la misma
  * y la devolvemos cuando encontremos el terminador.
  */

int LongitudCadena (const char * cadena) {
	int longitud = 0;

	while (*(cadena + longitud) != '\0')
		longitud++;

	return longitud;
}

/** @fn char * CopiarCadena (char * destino, const char * origen)
  * @brief Copia la cadena de origen en la de destino, sobreescribiéndola
  *
  * @param destino Cadena que se modifica según la cadena de origen
  * @param origen Cadena constante que se toma como referencia
  *
  * @return Copia de la cadena de origen
  *
  * Al igual que en LongitudCadena, desreferenciamos la cadena `origen` en base
  * a su longitud, ya que la longitud de la cadena original y la copiada van a
  * ser la misma y vamos a tener que introducir manualmente el terminador en la
  * cadena `destino` en el punto indicado por dicha `longitud`. De esta forma,
  * nos ahorramos tener que declarar y gestionar dos punteros, aumentando la
  * eficiencia en memoria y en tiempo de ejecución y haciendo el código más
  * sencillo de depurar.
  */

char * CopiarCadena (char * destino, const char * origen) {
	int longitud = 0;

	while (*(origen + longitud) != '\0') {
		*(destino + longitud) = *(origen + longitud);
		longitud++;
	}

	*(destino + longitud) = '\0';

	return destino;
}

/** @fn char * EncadenarCadena (char * destino, const char * origen)
  * @brief Concatena la cadena de origen tras la de destino
  *
  * @param destino Cadena que se modifica según la cadena de origen
  * @param origen Cadena constante que se toma como referencia
  *
  * Colocamos el punterio de `destino` en su terminador y copiamos
  * secuencialmente la cadena `origen` sobreescribiéndolo.
  */

char * EncadenarCadena (char * destino, const char * origen) {
	const char * p_origen  = origen;
	      char * p_destino = destino + LongitudCadena(destino);

	while (*p_origen != '\0')
		*(p_destino++) = *(p_origen++);

	*p_destino = '\0';

	return destino;
}

/** @fn char * EliminaBlancosIniciales (char * destino, const char * origen)
  * @brief Copia la cadena sin los espacios en blanco inciales
  *
  * @param destino Cadena que se modifica según la cadena de origen
  * @param origen Cadena constante que se toma como referencia
  *
  * Avancamos el puntero de `origen` hasta el primer espacio y después llamamos
  * a CopiarCadena para copiar el resto. Tenemos en cuenta que las funciones no
  * reciben una cadena, sino un puntero que indica su primera posición.
  */

char * EliminaBlancosIniciales (char * destino, const char * origen) {
	while (isspace(*origen))
		origen++;

	return CopiarCadena(destino, origen);
}

/** @fn char * EliminaBlancosFinales (char * destino, const char * origen)
  * @brief Copia la cadena sin los espacios en blanco finales
  *
  * @param destino Cadena que se modifica según la cadena de origen
  * @param origen Cadena constante que se toma como referencia
  *
  * Computamos la `longitud` de la cadena y la reducimos por tantas unidades
  * como espacios tenga al final. Tras esto, llamamos a Subcadena para extraer
  * una cadena que vaya desde el inicio hasta el último carácter no blanco
  * indicado por la `longitud`.
  */

char * EliminaBlancosFinales (char * destino, const char * origen) {
	int longitud = LongitudCadena(origen);

	while (isspace(*(origen + longitud - 1)))
		longitud--;

	return Subcadena(destino, origen, 0, longitud);
}

/** @fn char * EliminaBlancosExtremos (char * destino, const char * origen)
  * @brief Copia la cadena sin los espacios en blanco iniciales ni finales
  *
  * @param destino Cadena que se modifica según la cadena de origen
  * @param origen Cadena constante que se toma como referencia
  *
  * Aprovechamos las definiciones de EliminaBlancosIniciales y
  * EliminaBlancosFinales para no repetir código.
  */

char * EliminaBlancosExtremos (char * destino, const char * origen) {
	return EliminaBlancosIniciales(destino,
	                               EliminaBlancosFinales(destino, origen));
}

/** @fn char * EliminaBlancosIntermedios (char * destino, const char * origen)
  * @brief Copia la cadena sin los espacios en blanco entre las palabras
  *
  * @param destino Cadena que se modifica según la cadena de origen
  * @param origen Cadena constante que se toma como referencia
  *
  * Eliminamos los espacios intermedios en cuatro bucles:
  *
  * - Determinamos la posición del primer blanco final
  * - Copiamos los blancos iniciales
  * - Copiamos hasta el primer blanco final evitando los blancos intermedios
  * - Copiamos los blancos finales
  */

char * EliminaBlancosIntermedios (char * destino, const char * origen) {
	const char * p_origen  = origen,
	           * pr_origen = origen + LongitudCadena(origen);
	      char * p_destino = destino;

	while (isspace(*(pr_origen-1)))
		pr_origen--;

	while (isspace(*p_origen))
		*(p_destino++) = *(p_origen++);

	while (p_origen < pr_origen) {
		while (isspace(*p_origen))
			p_origen++;

		*(p_destino++) = *(p_origen++);
	}

	while (*p_origen != '\0')
		*(p_destino++) = *(p_origen++);

	*p_destino = '\0';

	return destino;
}

/** @fn char * EliminaTodosBlancos (char * destino, const char * origen)
  * @brief Elimina todos los espacios en blancos de una cadena
  *
  * @param destino Cadena que se modifica según la cadena de origen
  * @param origen Cadena constante que se toma como referencia
  *
  * Aunque podríamos llamar a EliminaBlancosExtremos y EliminaBlancosIntermedios
  * (y esta solución se encuentra comentada en la definición de la función)
  * resulta más eficiente en tiempo y espacio redefinirla para que simplemente
  * copie todo lo que no sea un espacio.
  */

char * EliminaTodosBlancos (char * destino, const char * origen) {
	const char * p_origen  = origen;
	      char * p_destino = destino;

	while (*p_origen != '\0') {
		while (isspace(*p_origen))
			p_origen++;

		*(p_destino++) = *(p_origen++);
	}

	return destino;
}

/** @fn char * Invertir (char * destino, const char * origen)
  * @brief Copia la cadena de origen invertida en la de destino
  *
  * @param destino Cadena que se modifica según la cadena de origen
  * @param origen Cadena constante que se toma como referencia
  *
  * Colocamos el puntero reverso en el último carácter de la cadena apoyándonos
  * de LongitudCadena y lo vamos desplazando hacia atrás hasta que lleguemos al
  * primer carácter de `origen`, copiando su valor en posiciones incrementales
  * de la `destino`. Para copiar el primer carácter de `origen` (el último de
  * `destino`) podríamos simplemente copiar `*pr_origen`, pero nos decantamos
  * por realizar la asignación mediante `*origen` para dejar patente que, en
  * cualquier caso, el valor copiado será el primero de la cadena.
  */

char * Invertir (char * destino, const char * origen) {
	const char * pr_origen = origen + LongitudCadena(origen) - 1;
	      char * p_destino = destino;

	while (pr_origen > origen)
		*(p_destino++) = *(pr_origen--);

	*(p_destino++) = *origen;
	*p_destino     = '\0';

	return destino;
}

/** @fn char * Subcadena (char * destino, const char * origen, int pos, int lon)
  * @brief Extrae una subcadena de una cadena de caracteres
  *
  * @param destino Cadena que se modifica según la cadena de origen
  * @param origen Cadena constante que se toma como referencia
  * @param pos Posición de inicio de la subcadena en la cadena de origen
  * @param lon Longitud de la subcadena a partir de la posición de referencia
  *
  * Para el bucle, además de comprobar que no hayamos realizado más iteraciones
  * que las indicadas por `lon`, también tenemos en cuenta que no nos hayamos
  * encontrado con el terminador, en cuyo caso paramos el bucle y devolvemos una
  * subcadena de menor longitud.
  */

char * Subcadena (char * destino, const char * origen, int pos, int lon) {
	const char * p_origen  = origen + pos;
	      char * p_destino = destino;

	for (int i = 0; i < lon && *p_origen != '\0'; i++)
		*(p_destino++) = *(p_origen++);

	*p_destino = '\0';

	return destino;
}
