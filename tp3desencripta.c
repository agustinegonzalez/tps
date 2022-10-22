#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int n, n1,n2,n3,n4;
	printf ("Este programa es encriptador de un entero de cuatro digitos\n\n");
	
	printf ("Ingrese el entero positivo: \n");
	scanf ("%d", &n);
	
	if ( n <= 9999 ) {
		n1 = n % 10;
		n = n / 10;
		n2 = n % 10;
		n = n / 10;
		n3 = n % 10;
		n = n/10;
		n4 = n;
		
		n1 = (n1+3) * 100;
		n2 = (n2+3) * 1000;
		n3 = (n3+3) * 1;
		n4 = (n4+3) * 10;
		
		printf("El numero cifrado es %d", n1 + n2 + n3 + n4);
	}
	else {
		printf("Le pedi que ingrese un numero de cuatro cifras. El numero no es valido");
	}
	
	
	
	return 0;
}

