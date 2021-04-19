service Calculadora
{
	void Ping ();

	i32 SumaEscalar     (1: i32 operando1, 2: i32 operando2);
	i32 RestaEscalar    (1: i32 operando1, 2: i32 operando2);
	i32 ProductoEscalar (1: i32 operando1, 2: i32 operando2);
	i32 DivisionEscalar (1: i32 operando1, 2: i32 operando2);

	list<i32> SumaVectorial     (1: list<i32> operando1, 2: list<i32> operando2);
	list<i32> RestaVectorial    (1: list<i32> operando1, 2: list<i32> operando2);
	list<i32> ProductoVectorial (1: list<i32> operando1, 2: list<i32> operando2);

	list<list<i32>> SumaMatricial     (1: list<list<i32>> operando1, 2: list<list<i32>> operando2);
	list<list<i32>> RestaMatricial    (1: list<list<i32>> operando1, 2: list<list<i32>> operando2);
	list<list<i32>> ProductoMatricial (1: list<list<i32>> operando1, 2: list<list<i32>> operando2);
}
