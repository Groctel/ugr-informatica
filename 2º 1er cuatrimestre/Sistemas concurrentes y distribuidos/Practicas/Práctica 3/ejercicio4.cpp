/*
 * NOMBRE:    Atanasio José
 * APELLIDOS: Rubio Gil
 * DNI:       44599757C
 */

#include <iostream>
#include <thread> // this_thread::sleep_for
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include <mutex>
#include <mpi.h>

const int
   id_productor          = 4,  // Identificador del proceso productor
   id_consumidor         = 8,  // Identificador del proceso consumidor
   id_buffer             = 9,  // Identificador del proceso buffer
   id_dormitorio         = 10, // Identificador del proceso dormitorio
   num_procesos_esperado = 11, // Número total de procesos esperado
   num_items             = 20, // Numero de items producidos o consumidos
	tam_vector            = 10, // Tamaño del vector de valores
	etiq_producir         = 0,  // Etiqueta de los productores
	etiq_consumir         = 1,  // Etiqueta de los consumidores
	etiq_dormir           = 2,  // Etiqueta del dormitorio
	etiq_despertar        = 3;  // Etiqueta del dormitorio
std::mutex mtx;

/** @brief Generador de número enteros aleatorios
  * Devuelve un número entero comprendido en el intervalo [min, max).
  *
  * @param min Número mínimo que devolver (inclusive)
  * @param max Número máximo que devolver (no inclusive)
  */

template <int min, int max>
int aleatorio () {
  static std::default_random_engine generador((std::random_device())());
  static std::uniform_int_distribution<int> distribucion_uniforme(min, max);
  return distribucion_uniforme(generador);
}

/** @brief Función de producción de un valor
  * Empezando desde el 0, produce valores secuencialmente aumentándolos en 1
  * cada vez. Se espera un número aleatorio de milisegundos y, tras producir el
  * valor, lo devuelve para su envío al consumidor.
  */

int producir () {
	static int contador = 0;
	int dormir = 0;

	mtx.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(aleatorio<10,200>()));

	contador++;

	std::cout << "Productor ha producido valor " << contador
	          << std::endl << std::flush;

	mtx.unlock();
	return contador;
}

/** @brief Función a ejecutar por el proceso productor
  * En cada producción recogemos un valor de la función producir(), lo mostramos
  * por stdout y lo enviamos al buffer.
  */

void funcion_productor () {
/*
 * Ejecutamos el productor tantas veces como mensajes se vayan a enviar al
 * consumidor.
 */
	for (unsigned i=0; i<num_items; i++) {
		int valor_prod = producir();

		std::cout << "Productor va a enviar valor " << valor_prod
		          << std::endl << std::flush;

		MPI_Ssend(&valor_prod, 1, MPI_INT, id_buffer, etiq_producir,
		          MPI_COMM_WORLD);

		int dormir = aleatorio<30,50>();
		if (dormir >= 46) {
			MPI_Ssend(&valor_prod, 1, MPI_INT, id_dormitorio, etiq_dormir,
			          MPI_COMM_WORLD);

			std::this_thread::sleep_for(std::chrono::milliseconds(
			                                         aleatorio<20,30>()));

			MPI_Ssend(&valor_prod, 1, MPI_INT, id_dormitorio, etiq_despertar,
						MPI_COMM_WORLD);
		}
	}
}

/** @brief Función de consumición de un valor
  * Se espera un número aleatorio de milisegundos y se consume mostrándolo por
  * stdout.
  *
  * @param valor Valor a consumir
  */

void consumir (const int valor) {
	std::this_thread::sleep_for(std::chrono::milliseconds(aleatorio<10,200>()));
	std::cout << "Consumidor ha consumido valor " << valor << std::endl
	          << std::flush;
}

/** @brief Función a ejecutar por el proceso consumidor
  * En cada consumición se envía una petición de recepción al buffer para que
  * éste le envíe el valor, se recibe de mismo, y se envía a la función de
  * consumición.
  */

void funcion_consumidor () {
	int peticion = 0,
	    valor_rec = 0;
	MPI_Status estado;
/*
 * Ejecutamos el consumidor tantas veces como mensajes se vayan a recibir de
 * parte del productor por el número de consumidores
 */
	for (unsigned i=0; i<num_items*2*(id_consumidor-id_productor); i++) {
	 
		MPI_Ssend(&peticion, 1, MPI_INT, id_buffer, etiq_consumir,
		          MPI_COMM_WORLD);

		MPI_Recv(&valor_rec, 1, MPI_INT, id_buffer, etiq_consumir, MPI_COMM_WORLD,
		         &estado);

		std::cout << "Consumidor  ha recibido valor " << valor_rec
		          << std::endl << std::flush;

		consumir(valor_rec);
	}
}

/** @brief Función a ejecutar por el proceso buffer
  * Para cada valor transmitido entre el productor y el consumidor, el buffer
  * recibe primero el valor del productor, luego recibe la petición de parte del
  * consumidor y le envía el valor, completando la transmisión.
  */

void funcion_buffer () {
	int valor,    // Valor transmitido entre el productor y el consumidor
	    peticion; // Valor para almacenar la petición del consumidor
	MPI_Status estado; // Estado de la recepción del mensaje

/*
 * Ejecutamos el buffer tantas veces como mensajes se vayan a compartir entre el
 * productor y el consumidor.
 */
	for (unsigned i=0; i<num_items*(id_productor+id_consumidor); i++) {
		MPI_Recv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_producir,
		         MPI_COMM_WORLD, &estado);

		std::cout << "Buffer ha recibido valor " << valor << std::endl;

		MPI_Recv(&peticion, 1, MPI_INT, MPI_ANY_SOURCE, etiq_consumir,
		         MPI_COMM_WORLD, &estado);

		std::cout << "Buffer va a enviar valor " << valor << std::endl;

		MPI_Ssend(&valor, 1, MPI_INT, estado.MPI_SOURCE, etiq_consumir,
		          MPI_COMM_WORLD);
   }
}

/** @brief Función dormitorio
  *
  */

void funcion_dormitorio () {
	int peticion,
	    etiq_aceptable,
	    dormidos = 0;
	MPI_Status estado;

	while (true) {
		if (dormidos == 0)
			etiq_aceptable = etiq_dormir;
		else if (dormidos <= (id_productor+1) / 2)
			etiq_aceptable = MPI_ANY_TAG;
		else
			etiq_aceptable = etiq_despertar;

		MPI_Recv(&peticion, 1, MPI_INT, MPI_ANY_SOURCE, etiq_aceptable,
		         MPI_COMM_WORLD, &estado);

		if (estado.MPI_TAG == etiq_dormir) {
			dormidos++;
			std::cout << "El productor " << estado.MPI_SOURCE
			 	       << " comienza a descansar" << std::endl;
		}
		else if (estado.MPI_TAG == etiq_despertar) {
			dormidos--;
			std::cout << "El productor " << estado.MPI_SOURCE
			          << " ha termidado de descansar" << std::endl;
		}
		else {
			std::cerr << "Esto no debería salir!!!11!!";
		}
	}
}

/** @brief Función principal
  * Inicializa los parámetros de ejecución propios de OpenMPI y ejecuta las
  * funciones del productor, buffer o consumidor según corresponda.
  *
  * @param argc Número de argumentos con los que se ejecuta el programa
  * @param argv Lista de argumentos con los que se ejecuta el programa
  */

int main (int argc, char** argv) {
	int id_propio,           // Número identificador del proceso
	    num_procesos_actual; // Número total de procesos
/*
 * Llamamos a la orden MPI_Init para inicializar el programa con argumentos
 * válidos para MPI.
 */
	MPI_Init(&argc, &argv);
/*
 * Damos valor a num_procesos_actual, recogido desde el argumento -np de la
 * orden de ejecución.
 */
	MPI_Comm_size(MPI_COMM_WORLD, &num_procesos_actual);
/*
 * Damos valor al id_propio de este proceso, que toma cualquier valor de [0,n-1]
 * donde n es num_procesos_actual.
 */
	MPI_Comm_rank(MPI_COMM_WORLD, &id_propio);
/*
 * Comenzamos la ejecución del programa si el número de procesos que componen el
 * programa es igual a num_procesos_esperado. En cualquier otro caso, enviamos
 * un mensaje de error informando de este hecho.
 */
	if (num_procesos_esperado == num_procesos_actual) {
	/*
	 * Ejecutamos la función del productor, del buffer o de los consumidores en
	 * función del id_propio de cada uno de los procesos.
	 */
		if (id_propio <= id_productor) {
			funcion_productor();
		}
		else if (id_propio <= id_consumidor) {
			funcion_consumidor();
		}
		else if (id_propio == id_buffer) {
			funcion_buffer();
		}
		else {
			funcion_dormitorio();
		}
	}
	else if (id_propio == 0) {
	/*
	 * En caso de que se hayan inicializado un número de procesos incorrecto,
	 * informamos de ello mediante un mensaje de error. Incluimos una condición
	 * de que el id_propio debe ser 0 para enviar este mensaje una sola vez.
	 */
		std::cerr << "error: número de procesos distinto del esperado."
		          << std::endl;
	}
/*
 * Finalizamos la hebra de MPI.
 */
	MPI_Finalize();
	return 0;
}

