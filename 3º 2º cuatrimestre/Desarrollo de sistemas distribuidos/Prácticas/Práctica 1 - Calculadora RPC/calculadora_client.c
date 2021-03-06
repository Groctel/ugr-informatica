/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "calculadora.h"

#define OpSuma     '+'
#define OpResta    '-'
#define OpProducto '*'
#define OpCociente '/'

void TextoAyuda ()
{
	FILE * fptr = fopen("./man.txt", "r");

	if (!fptr)
	{
		printf("'man.txt' no encontrado. Reinstale el programa para recibir el manual.\n");
	}
	else
	{
		char c = fgetc(fptr);
		while (c != EOF)
		{
			printf ("%c", c);
			c = fgetc(fptr);
		}

		fclose(fptr);
	}

	exit (1);
}

void OperacionEscalar (int valor1, char operador, int valor2, char * host)
{
	CLIENT *clnt;
	resultado_escalar * resultado;

	#ifndef DEBUG
		clnt = clnt_create(host, CALCULADORA_PROG, CALCULADORA_VER, "udp");
		if (clnt == NULL)
		{
			clnt_pcreateerror(host);
			exit(1);
		}
	#endif

	if (operador == OpSuma)
	{
		resultado = suma_1(valor1, valor2, clnt);
	}
	else if (operador == OpResta)
	{
		resultado = resta_1(valor1, valor2, clnt);
	}
	else if (operador == OpProducto)
	{
		resultado = producto_1(valor1, valor2, clnt);
	}
	else if (operador == OpCociente)
	{
		resultado = cociente_1(valor1, valor2, clnt);
	}
	else
	{
		TextoAyuda();
	}

	if (resultado == (resultado_escalar *) NULL)
		clnt_perror (clnt, "call failed");

	printf("%d\n", resultado->resultado_escalar_u.resultado);

#ifndef DEBUG
	clnt_destroy (clnt);
#endif
}

void OperacionVectorial (
	vecx * valor1,
	char operador,
	vecx * valor2,
	int escalar,
	char * host
) {
	CLIENT *clnt;
	resultado_vectorial * resultado;

	#ifndef DEBUG
		clnt = clnt_create(host, CALCULADORA_PROG, CALCULADORA_VER, "udp");
		if (clnt == NULL)
		{
			clnt_pcreateerror(host);
			exit(1);
		}
	#endif

	if (operador == OpSuma && valor1 && valor2)
	{
		resultado = sumavec_1(*valor1, *valor2, clnt);
	}
	else if (operador == OpResta && valor1 && valor2)
	{
		resultado = restavec_1(*valor1, *valor2, clnt);
	}
	else if (operador == OpProducto)
	{
		if (valor1 && valor2)
			resultado = productovec_1(*valor1, *valor2, clnt);
		else if (valor1)
			resultado = productovecsc_1(*valor1, escalar, clnt);
		else if (valor2)
			resultado = productovecsc_1(*valor2, escalar, clnt);
	}
	else
	{
		TextoAyuda();
	}

	if (resultado == (resultado_vectorial *) NULL)
		clnt_perror (clnt, "call failed");

	vecx vector_resultado = resultado->resultado_vectorial_u.resultado;
	u_int tam             = vector_resultado.vecx_len;
	int * datos           = vector_resultado.vecx_val;

	printf("(%d", datos[0]);
	for (unsigned int i = 1; i < tam; i++)
		printf(",%d", datos[i]);
	printf(")\n");

	#ifndef DEBUG
		clnt_destroy (clnt);
	#endif
}

void OperacionMatricial (
	matx * valor1,
	char operador,
	matx * valor2,
	int escalar,
	char * host
) {
	CLIENT *clnt;
	resultado_matricial * resultado;

	#ifndef DEBUG
		clnt = clnt_create(host, CALCULADORA_PROG, CALCULADORA_VER, "udp");
		if (clnt == NULL)
		{
			clnt_pcreateerror(host);
			exit(1);
		}
	#endif

	if (operador == OpSuma && valor1 && valor2)
	{
		resultado = sumamat_1(*valor1, *valor2, clnt);
	}
	else if (operador == OpResta && valor1 && valor2)
	{
		resultado = restamat_1(*valor1, *valor2, clnt);
	}
	else if (operador == OpProducto)
	{
		if (valor1 && valor2)
			resultado = productomat_1(*valor1, *valor2, clnt);
		else if (valor1)
			resultado = productomatsc_1(*valor1, escalar, clnt);
		else if (valor2)
			resultado = productomatsc_1(*valor2, escalar, clnt);
	}
	else
	{
		TextoAyuda();
	}

	if (resultado == (resultado_matricial *) NULL)
		clnt_perror (clnt, "call failed");

	matx matriz_resultado = resultado->resultado_matricial_u.resultado;
	u_int orden           = matriz_resultado.orden;
	vecx * filas          = matriz_resultado.filas;

	printf("[");
	for (int i = 0; i < orden; i++)
	{
		u_int tam   = filas[i].vecx_len;
		int * datos = filas[i].vecx_val;

		printf("(%d", datos[0]);
		for (unsigned int j = 1; j < tam; j++)
			printf(",%d", datos[j]);
		printf(")");
	}
	printf("]\n");

	#ifndef DEBUG
		clnt_destroy (clnt);
	#endif
}

bool EsVector (char * operando)
{
	bool es_vector = (operando[0] == '(' && operando[strlen(operando)-1] == ')');

	if (es_vector)
	{
		for (int i = 1; i < strlen(operando)-1; i++)
			es_vector = (isdigit(operando[i]) || operando[i] == ',');
	}

	return es_vector;
}

bool EsMatriz (char * operando)
{
	bool es_matriz = (operando[0] == '[' && operando[strlen(operando)-1] == ']');

	if (es_matriz)
	{
		for (int i = 1; i < strlen(operando)-1; i++)
			es_matriz = (
				isdigit(operando[i]) ||
				operando[i] == ',' ||
				operando[i] == '(' ||
				operando[i] == ')'
			);
	}

	return es_matriz;
}

bool AmbosOperandosSonEscalares (char * operando1, char * operando2)
{
	return isdigit(operando1[0]) && isdigit(operando2[0]);
}

bool AlMenosUnOperandoEsVectorial (char * operando1, char * operando2)
{
	return (EsVector(operando1) || EsVector(operando2));
}

bool AlMenosUnOperandoEsMatricial (char * operando1, char * operando2)
{
	return (EsMatriz(operando1) || EsMatriz(operando2));
}

vecx * ExtraerVector (char * operando)
{
	vecx * vector_extraido = 0;

	if (EsVector(operando))
	{
		unsigned int tam_vector = 1;

		for (unsigned int i = 1; i < strlen(operando); i++)
		{
			if (operando[i] == ',')
				tam_vector++;
		}

		vector_extraido           = malloc(sizeof(vecx));
		vector_extraido->vecx_val = malloc(sizeof(int[tam_vector]));
		vector_extraido->vecx_len = 0;

		for (unsigned int i = 1; i < strlen(operando); i++)
		{
			unsigned int j = 0;
			char buffer_numero[32];

			while (operando[i] != ',' && operando[i] != ')')
				buffer_numero[j++] = operando[i++];

			buffer_numero[j] = '\0';
			vector_extraido->vecx_val[vector_extraido->vecx_len++] = atoi(buffer_numero);
		}
	}

	return vector_extraido;
}

matx * ExtraerMatriz (char * operando)
{
	matx * matriz_extraida = 0;

	if (EsMatriz(operando))
	{
		unsigned int num_filas = 0;

		for (unsigned int i = 1; i < strlen(operando)-1; i++)
		{
			if (operando[i] == '(')
				num_filas++;
		}

		matriz_extraida        = malloc(sizeof(matx));
		matriz_extraida->filas = malloc(sizeof(vecx[num_filas]));
		matriz_extraida->orden = num_filas;

		unsigned int pos_vector = 1;

		for (unsigned int i = 0; i < matriz_extraida->orden; i++)
		{
			int lon_vector = pos_vector;

			while (operando[lon_vector] != ')')
				lon_vector++;

			char * siguiente_fila = malloc(sizeof(char[lon_vector-pos_vector+2]));
			strncpy(siguiente_fila, operando+pos_vector, lon_vector-pos_vector+1);

			matriz_extraida->filas[i] = *ExtraerVector(siguiente_fila);

			free(siguiente_fila);
			pos_vector = lon_vector+1;
		}
	}

	return matriz_extraida;
}

void InterpretarOperacionVectorial (
	char * operando1,
	char * operador,
	char * operando2,
	char * host
) {
	vecx * vector1 = ExtraerVector(operando1);
	vecx * vector2 = ExtraerVector(operando2);
	int escalar;

	if (!vector1)
		escalar = atoi(operando1);

	if (!vector2)
		escalar = atoi(operando2);

	OperacionVectorial(vector1, operador[0], vector2, escalar, host);

	if (vector1)
	{
		free(vector1->vecx_val);
		free(vector1);
	}

	if (vector2)
	{
		free(vector2->vecx_val);
		free(vector2);
	}
}

void InterpretarOperacionMatricial (
	char * operando1,
	char * operador,
	char * operando2,
	char * host
) {
	matx * matriz1 = ExtraerMatriz(operando1);
	matx * matriz2 = ExtraerMatriz(operando2);
	int escalar;

	if (!matriz1)
		escalar = atoi(operando1);

	if (!matriz2)
		escalar = atoi(operando2);

	OperacionMatricial(matriz1, operador[0], matriz2, escalar, host);

	if (matriz1)
	{
		for (unsigned int i = 0; i < matriz1->orden; i++)
			free(matriz1->filas[i].vecx_val);

		free(matriz1->filas);
		free(matriz1);
	}

	if (matriz2)
	{
		for (unsigned int i = 0; i < matriz1->orden; i++)
			free(matriz2->filas[i].vecx_val);

		free(matriz2->filas);
		free(matriz2);
	}
}

void InterpretarArgumentos (int argc, char ** argv)
{
	char * host      = argv[1];
	char * operando1 = argv[2];
	char * operador  = argv[3];
	char * operando2 = argv[4];

	if (AmbosOperandosSonEscalares(operando1, operando2))
	{
		OperacionEscalar(atoi(operando1), operador[0], atoi(operando2), host);
	}
	else if (AlMenosUnOperandoEsVectorial(operando1, operando2))
	{
		InterpretarOperacionVectorial(operando1, operador, operando2, host);
	}
	else if (AlMenosUnOperandoEsMatricial(operando1, operando2))
	{
		InterpretarOperacionMatricial(operando1, operador, operando2, host);
	}
}

int main (int argc, char ** argv)
{
	if (argc != 5)
		TextoAyuda();
	else
		InterpretarArgumentos(argc, argv);

	return 0;
}
