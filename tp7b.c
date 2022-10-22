#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int devuelve ();
char pregunta (int*, int*);
void mensaje(char);


int main() {
	srand(time(NULL));
		
	int a;
	int b;
	char respuesta;
		
	a = devuelve();
	b = devuelve();
		
	do{
	respuesta=pregunta(&a, &b);
	mensaje(respuesta);  
	}while(respuesta!='v');
		
	return 0;
}
	
int devuelve (){
	
	int a =(rand()%9)+1;
	return (a);
	
}

char pregunta (int *a, int *b) {

   int contesta;
   char valida;
   printf("¿Cuánto es %d por %d?: ", *a, *b);
   scanf("%d", &contesta);
   
   if(contesta==(*a)*(*b)){
   valida='v';
   }
   else{
   valida='f';
   }
   
   
   return valida;
}

void mensaje(char respuesta){
   int indice;
   char *mensajeaprobado[4]={"¡Muy bien!", "¡Excelente!","¡Buen trabajo!","¡Siga con el buen trabajo!"};
   
   if(respuesta=='v'){
      indice = (rand()%3);
      printf("%s\n", mensajeaprobado[indice]);
   }
   if(respuesta=='f'){
      switch((rand()%4+1)){
      case 1: printf("No. Por favor intente de nuevo\n");
      break;
      case 2:printf("Incorrecto. Intentar una vez más\n");
      break;
      case 3:printf("¡No te rindas!\n");
      break;
      case 4: printf("No. Sigue intentándolo\n");
      break;
      }
   }
}




