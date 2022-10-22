#include <stdio.h>
//tp2
int main(int argc, char *argv[]) {
	float a, R, p;

	printf ("Escriba el peso en kilogramos: ");
	scanf ("%f", &p);
	
	printf ("Escriba la altura en metros: ");
	scanf ("%f", &a);
	
	R = p / (a * a);
	
		printf("El IMC es: %.2f\n\n", R );
	
	printf ("VALORES BMI\nBajo peso: menos de 18.5\n");
	printf ("Normal: entre 18.5 y 24.9\nSobrepeso: entre 25 y 29.9\n");
	printf ("Obeso: 30 o más\n");
	return 0;
}

