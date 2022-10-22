#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 11
#define VECES 36000


int devolucion_rand();
void lanzamiento(int [], const int );
void imprimirVector(int [], const int);



int main() {
	
	int vector[TAM] = {0}; 
	srand(time(0));
	lanzamiento(vector, VECES);
	imprimirVector(vector, TAM);
	return 0;
}



int devolucion_rand() {
	return (rand() % 6) + 1;
}

void lanzamiento(int vector[], const int veces) {
	int tmp;
	for (int i = 0; i<veces; i++) {
		tmp = devolucion_rand() + devolucion_rand();
		printf("%d + %d = %d\n", devolucion_rand(), devolucion_rand(), tmp);
		vector[tmp - 2]++;
	}
}

void imprimirVector(int vector[], const int tam) {
	
	for(int j=0; j<tam; j++){
		printf("%d \t", j+2);
	}
	printf("\n");
	for(int i=0; i<tam; i++) {
		printf("%d\t",vector[i]);
	}
}
