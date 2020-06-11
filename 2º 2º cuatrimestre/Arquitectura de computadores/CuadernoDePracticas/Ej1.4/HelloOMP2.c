#include <stdio.h>
#include <omp.h>

int main () {
	#pragma omp parallel
		printf("(%d:Hello)",   omp_get_thread_num());
		printf("(%d:World)\n", omp_get_thread_num());

	return 0;
}
