#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NPREGUNTAS 10

int devuelve ();
char pregunta (int*, int*);
void mensaje(char, int *, int);


int main() {
	srand(time(NULL));
	
	int a;
	int b;
	char respuesta;
	int contador[2]={0};
	
	for(int i=0; i<NPREGUNTAS; i++){
	   printf("Pregunta [%d]: \n", i+1);
	   
	   a = devuelve();
	   b = devuelve();
	   
		int respondida=0;   
	   do{
	   respuesta=pregunta(&a, &b);
	   mensaje(respuesta, &contador[0], respondida); 
	   respondida=1;
	   }while(respuesta!='v');
	}
		
	printf("Respuesta correctas: %d\nRespuestas incorrectas: %d\n", contador[1], contador[0]);	
	printf("Porcentaje de correctas: %.0f\n", (((float)contador[1])/NPREGUNTAS)*100);
	printf("Porcentaje de incorrectas: %.0f\n", (((float)contador[0])/NPREGUNTAS)*100);

   
	return 0;
}
	
int devuelve (){
	int a=(rand()%9)+1;
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

void mensaje(char respuesta, int *cuenta, int respondida){

   
   if(respuesta=='v'){
      if(respondida==0){
      cuenta[1]++;
      }
      switch ((rand()%4+1)){
      case 1: printf("¡Muy bien!\n");
      break;
      case 2:printf("¡Excelente!\n");
      break;
      case 3:printf("¡Buen trabajo!\n");
      break;
      case 4:printf("Siga con el buen trabajo!\n");
      break;
      }
   }
   if(respuesta=='f'){
      if(respondida==0){
      cuenta[0]++;
      }
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
