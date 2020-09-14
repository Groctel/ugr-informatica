#include <cstdio>
#include <ctime>
#include <vector>
#include "bintree.cpp"

void Sencillo (std::vector<int> pre, unsigned raiz, unsigned tope/*, bool** matriz*/) {
	for (unsigned i=raiz; i<tope; i++) {
		if (i+1 < tope && pre[i+1]<pre[i]) {
			//matriz[pre[i]-1][pre[i+1]-1] = true;
		}
		else if (i+1 < tope) {
			int mas_alto = 0;

			for (unsigned j=i; j>raiz; j--) {
				if (pre[j] > mas_alto)
					mas_alto = pre[j];
			}

			//matriz[mas_alto-1][pre[i+1]-1] = true;
		}
	}
}

void DyV (std::vector<int> pre, unsigned raiz, unsigned tope/*, bool** matriz*/) {
	unsigned i;

	for (i=raiz+1; i<tope && pre[i]<pre[raiz]; i++);

	if (i<tope) {
		//matriz[pre[raiz]-1][pre[raiz+1]-1] = true;
		//matriz[pre[raiz]-1][pre[i]-1] = true;
		DyV (pre, i, tope/*, matriz*/);
		DyV (pre, raiz+1, i/*, matriz*/);
	}
	else if (pre[raiz] != pre[i-1]) {
		//matriz[pre[raiz]-1][pre[i-1]-1] = true;
		DyV (pre, raiz+1, i/*, matriz*/);
	}
}

int main (int argc, char** argv) {
	std::vector<int> v;
	BinarySearchTree b;
	double ncgt;
	struct timespec cgt1,
	                cgt2;

	for (int i=10; i<500; i+=10) {
		for (int j=0; j<i; i++)
			b.insert(j);

		v = b.print_preorder();

		clock_gettime(CLOCK_REALTIME,&cgt1);
			DyV(v, 0, v.size());
		clock_gettime(CLOCK_REALTIME,&cgt1);

		ncgt = (double) (cgt2.tv_sec-cgt1.tv_sec) +
		       (double) ((cgt2.tv_nsec-cgt1.tv_nsec) / (1.e+9));

		printf("%d %lf", i, ncgt);
	}

	return 0;
}

/*
int main (int argc, char** argv) {
	unsigned* pre = new unsigned[7];
	bool** matriz_seq = new bool*[10];
	bool** matriz_dyv = new bool*[10];

	for (unsigned i=0; i<10; i++) {
		matriz_seq[i] = new bool[10];
		matriz_dyv[i] = new bool[10];
	}

	pre[0] = (7);
	pre[1] = (4);
	pre[2] = (3);
	pre[3] = (6);
	pre[4] = (5);
	pre[5] = (8);
	pre[6] = (10);

	Sencillo(pre, 0, 7, matriz_seq);

	for (unsigned i=0; i<10; i++) {
		for (unsigned j=0; j<10; j++)
			printf("%d ", matriz_seq[i][j]);

		printf("\n");
	}

	DyV(pre, 0, 7, matriz_dyv);
	printf("\n");

	for (unsigned i=0; i<10; i++) {
		for (unsigned j=0; j<10; j++)
			printf("%d ", matriz_dyv[i][j]);

		printf("\n");
	}

	delete pre;
	delete [] matriz_seq;
	delete [] matriz_dyv;

	return 0;
}*/
