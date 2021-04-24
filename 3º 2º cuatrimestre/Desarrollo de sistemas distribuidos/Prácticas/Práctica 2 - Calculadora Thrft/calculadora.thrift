service Calculadora
{
	void ping ();

	i32 suma_escalar     (1: i32 operando1, 2: i32 operando2);
	i32 resta_escalar    (1: i32 operando1, 2: i32 operando2);
	i32 producto_escalar (1: i32 operando1, 2: i32 operando2);
	i32 division_escalar (1: i32 operando1, 2: i32 operando2);

	list<i32> suma_vectorial     (1: list<i32> operando1, 2: list<i32> operando2);
	list<i32> resta_vectorial    (1: list<i32> operando1, 2: list<i32> operando2);
	list<i32> producto_vectorial (1: list<i32> operando1, 2: list<i32> operando2);

	list<list<i32>> suma_matricial     (1: list<list<i32>> operando1, 2: list<list<i32>> operando2);
	list<list<i32>> resta_matricial    (1: list<list<i32>> operando1, 2: list<list<i32>> operando2);
	list<list<i32>> producto_matricial (1: list<list<i32>> operando1, 2: list<list<i32>> operando2);
}
