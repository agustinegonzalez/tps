#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int devuelve ();
int pregunta (int*, int*);
void mensaje(int);


int main() {
	srand(time(NULL));
		
	int a;
	int b;
	int respuesta;
		
	a = devuelve();
	b = devuelve();
		
	do{
	respuesta=pregunta(&a, &b);
	mensaje(respuesta);  
	}while(respuesta!=1);
		
	return 0;
}
	
int devuelve (){
	
	int a =(rand()%9)+1;
	
	return (a);
}

int pregunta (int *a, int *b) {

   int contesta;
   printf("¿Cuánto es %d por %d?: ", *a, *b);
   scanf("%d", &contesta);
   
   if(contesta==(*a)*(*b)){
   contesta=1;
   }
   else{
   contesta==0;
   }
   
   return contesta;
}

void mensaje(int respuesta){

   if(respuesta==1){
   printf("¡Muy bien!\n");
   }
   else{
   printf("No. Intentelo nuevamente.\n");
   }
}




