union resultado_calculo switch (int err)
{
	case 0:
		int resultado;
	default:
		void;
};

program CALCULADORA_PROG
{
	version CALCULADORA_VER
	{
		resultado_calculo Suma     (int, int) = 1;
		resultado_calculo Resta    (int, int) = 2;
		resultado_calculo Producto (int, int) = 3;
		resultado_calculo Cociente (int, int) = 4;
	} = 1;
} = 20000001;
