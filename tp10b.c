#include <stdio.h> 

union flotante
{ 
	float f; 
	struct
	{ 
	  unsigned int mantisa : 23; 
		unsigned int exponente : 8; 
		unsigned int signo : 1; 
	}tipo; 
}; 

void imprimebinario(int, int);
void imprimir(union flotante var);

union flotante carga(union flotante *aux)
{
  printf("Ingrese el numero que desea imprimir en binario: "); 
	scanf("%f", &aux->f);
	
	return *aux;
}

int main() 
{ 
	union flotante var;
	
	var=carga(&var); 
	
	
	printf("El numero %.2f representado en el formate IEEE754 es: \n", var.f); 
	imprimir(var); /*paso union*/
	
return 0; 
}
 
void imprimebinario(int n, int i) 
{ 
	int k; 
	for (k = i-1; k >=0; k--) { 	
		if ((n >> k)&1) 
			printf("1"); 
		else
			printf("0"); 
	} 
}

void imprimir(union flotante var) 
{ 
	printf("%d | ", var.tipo.signo); 
	imprimebinario(var.tipo.exponente, 8); 
	printf(" | "); 
	imprimebinario(var.tipo.mantisa, 23); 
	printf("\n"); 
	printf("bit de signo: (%u)", var.tipo.signo);
	printf("\nbits del exponente: "); imprimebinario(var.tipo.exponente, 8); printf("(%u)\n",var.tipo.exponente);
  printf("bits de la mantisa: ");   imprimebinario(var.tipo.mantisa,23);    printf("(%u)\n", var.tipo.mantisa);

} 

 
