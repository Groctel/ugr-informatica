#include <clocale>
#include <cstdio>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include "rectangulo.hpp"

const unsigned MAX_RECTANGULOS = 10,
               BASELINE = 22,
               PRINT = 23,
               SCAN = 24;

int main () {
	unsigned num_rectangulos;
	std::string solucion = "SOLUCIÓN: ";
	WINDOW* ventana;

	setlocale(LC_CTYPE, "");
	initscr();
	curs_set(0);

	printw("%s\n%s\n- %s: %d\n- %s: %d\n- %s: %d\n\n%s",
	       "A continuación introducirá los datos programa de forma interactiva.",
	       "Tenga en cuenta las siguientes restricciones",
	       "Posición máxima de los rectángulos", Rectangulo::MAX_POSICION,
	       "Altura máxima de los rectángulos", Rectangulo::MAX_ALTURA,
	       "Anchura máxima de los rectángulos", Rectangulo::MAX_ANCHURA,
	       "Pulse cualquier tecla para continuar...");

	getch();

	mvprintw(0, 0, "\n\n\n\n\n\n\n");
	refresh();
	curs_set(1);

	ventana = newwin(26, 50, (LINES-26)/2, (COLS-50)/2);

	do {
		mvwprintw(ventana, PRINT, 1, "%s:\n", "Introduzca el número de rectángulos");
		box(ventana, 0, 0);
		wrefresh(ventana);
		mvwscanw(ventana, SCAN, 1, "%d", &num_rectangulos);
	} while (num_rectangulos == 0 || num_rectangulos > MAX_RECTANGULOS);

	Rectangulo* rectangulos = new Rectangulo[num_rectangulos];
	unsigned* skyline = new unsigned[40];

	for (unsigned i=5; i<5+40; i++)
		mvwaddch(ventana, BASELINE, i, '-');

	for (unsigned i=0; i<num_rectangulos; i++) {
		unsigned altura, anchura, posicion;
		char relleno[2];
		sprintf(relleno, "%d", i);

		do {
			mvwprintw(ventana, PRINT, 1, "Posición del rectángulo %d:\n\n", i);
			box(ventana, 0, 0);
			wrefresh(ventana);
			mvwscanw(ventana, SCAN, 1, "%d", &posicion);
		} while (posicion == 0 || posicion > Rectangulo::MAX_POSICION);

		mvwaddch(ventana, BASELINE-1, 5+posicion, relleno[0]);

		do {
			mvwprintw(ventana, PRINT, 1, "Altura del rectángulo %d:\n\n", i);
			box(ventana, 0, 0);
			mvwscanw(ventana, SCAN, 1, "%d", &altura);
			wrefresh(ventana);
		} while (altura == 0 || altura > Rectangulo::MAX_ALTURA);

		for (unsigned i=BASELINE-altura; i<BASELINE; i++)
			mvwaddch(ventana, i, 5+posicion, relleno[0]);

		do {
			mvwprintw(ventana, PRINT, 1, "Anchura del rectángulo %d:\n\n", i);
			box(ventana, 0, 0);
			mvwscanw(ventana, SCAN, 1, "%d", &anchura);
			wrefresh(ventana);
		} while (anchura == 0 || anchura > Rectangulo::MAX_ANCHURA);

		for (unsigned i=BASELINE-altura; i<BASELINE; i++)
			for (unsigned j=5+posicion+1; j<5+posicion+anchura; j++)
				mvwaddch(ventana, i, j, relleno[0]);

		rectangulos[i].SetDimensiones(altura, anchura, posicion);
	}

	for (unsigned i=0; i<num_rectangulos; i++) {
		for (unsigned j = rectangulos[i].Posicion();
		              j < rectangulos[i].Posicion() + rectangulos[i].Anchura();
		              j++) {
			if (rectangulos[i].Altura() > skyline[j])
				skyline[j] = rectangulos[i].Altura();
		}
	}

	for (unsigned i=0; i<40; i++)
		mvwaddch(ventana, BASELINE-skyline[i], 5+i, '=' | A_BOLD);

	mvwprintw(ventana, PRINT, 1, "%s\n%s",
	          "En la siguiente pantalla se mostrarán los datos",
	          "del problema desarrollados en tablas.");

	box(ventana, 0, 0);
	wrefresh(ventana);
	wgetch(ventana);

	for (unsigned i=0; i<26; i++)
		for (unsigned j=0; j<50; j++)
			mvwaddch(ventana, i, j, ' ');
	wrefresh(ventana);
	delwin(ventana);

	mvprintw(0, 0, "THE SKYLINE PROBLEM\n\nRectángulos utilizados:\n");

	printw("indice | posicion | altura | anchura\n"
	       "-------+----------+--------+--------\n");

	for (unsigned i=0; i<num_rectangulos; i++)
		printw ("%6d | %8d | %6d | %7d\n", i, rectangulos[i].Posicion(),
		        rectangulos[i].Altura(), rectangulos[i].Anchura());

	printw("\nSolución: %d", skyline[0]);

	for (int i=1; i<40; i++) {
		printw(", %d", skyline[i]);
	}

	printw("\n\nPulse cualquier tecla para finalizar...");

	refresh();
	curs_set(1);
	getch();

	endwin();

	return 0;
}
