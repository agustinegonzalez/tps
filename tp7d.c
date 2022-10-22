#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define NPREGUNTAS 10


int devuelve (int *);
char pregunta (int*, int*);
void mensaje(char, int *, int);
int dificultad();

int main() {
	srand(time(NULL));
	
	int a;
	int b;
	char respuesta;
	int contador[2]={0};
	int n;
	
	for(int i=0; i<NPREGUNTAS; i++){
	   printf("Pregunta [%d]: \n", i+1);
	   n = dificultad();
	   a = devuelve(&n);
	   b = devuelve(&n);
	   
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

int dificultad(){
   int n;
   printf("Ingrese el nivel de dificultad: ");
   scanf("%d", &n);
return (n);
}
	
int devuelve (int *n){
   int a;
   int b;
   
   b=(int)pow(10, *n);
   
   a=rand()%(b-1)+1;
   
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
   char *mensaje[4]={"¡Muy bien!", "¡Excelente!","¡Buen trabajo!","¡Siga con el buen trabajo!"};
   
   if(respuesta=='v'){
      if(respondida==0){
      cuenta[1]++;
      }
      int indice = (rand()%3);
      printf("%s\n", mensaje[indice]);
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
