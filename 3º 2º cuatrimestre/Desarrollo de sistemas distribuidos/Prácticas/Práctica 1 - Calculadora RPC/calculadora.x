typedef int vecx<>;

struct matx
{
	u_int  orden;
	vecx * filas;
};

typedef struct matx matx;

union resultado_escalar switch (int err)
{
	case 0:
		int resultado;
	default:
		void;
};

union resultado_vectorial switch (int err)
{
	case 0:
		vecx resultado;
	default:
		void;
};

union resultado_matricial switch (int err)
{
	case 0:
		matx resultado;
	default:
		void;
};

program CALCULADORA_PROG
{
	version CALCULADORA_VER
	{
		resultado_escalar Suma     (int, int) = 1;
		resultado_escalar Resta    (int, int) = 2;
		resultado_escalar Producto (int, int) = 3;
		resultado_escalar Cociente (int, int) = 4;

		resultado_vectorial SumaVec       (vecx, vecx) = 5;
		resultado_vectorial RestaVec      (vecx, vecx) = 6;
		resultado_vectorial ProductoVec   (vecx, vecx) = 7;
		resultado_vectorial ProductoVecSc (vecx, int) = 8;

		resultado_matricial SumaMat       (matx, matx) = 9;
		resultado_matricial RestaMat      (matx, matx) = 10;
		resultado_matricial ProductoMat   (matx, matx) = 11;
		resultado_matricial ProductoMatSc (matx, int) = 12;
	} = 1;
} = 20000001;
