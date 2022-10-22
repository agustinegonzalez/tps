#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define NPREGUNTAS 10


int devuelve (int);
char pregunta (int*, int*, int);
void mensaje(char, int *, int);
int dificultad();
int eligeoperacion();


int main() {
	srand(time(NULL));
	
	int a;
	int b;
	char respuesta;
	int contador[2]={0};
	int n;
	int opera;
	
	   opera=eligeoperacion();
	   n = dificultad();
	   for(int i=0; i<NPREGUNTAS; i++){
	   printf("\nPregunta [%d]: \n", i+1);
	   a = devuelve(n);
	   b = devuelve(n);
	   
		int respondida=0;   
	   do{
	   respuesta=pregunta(&a, &b, opera);
	   mensaje(respuesta, &contador[0], respondida); 
	   respondida=1;
	   }while(respuesta!='v');
	}
		
	printf("Respuesta correctas: %d\nRespuestas incorrectas: %d\n", contador[1], contador[0]);	
	printf("Porcentaje de correctas: %.0f\n", (((float)contador[1])/NPREGUNTAS)*100);
	printf("Porcentaje de incorrectas: %.0f\n", (((float)contador[0])/NPREGUNTAS)*100);
   
	return 0;
}

int eligeoperacion(){

   int op; 
   do{
   printf("Operaciones:\n1. Suma\n2. Resta\n3. Multiplicacion\n4. Mixto\n\nSeleccione la que quiera: ");
   scanf("%d", &op);
   if(!(op>0 && op<5)){
   printf("[[[ERROR]]] --> Usted a ingresado una operacion no registrada\n\n");
   }
   }while(!(op>0 && op<5));
   
   return (op);
}

int dificultad(){
   int n;
   printf("Ingrese el nivel de dificultad: ");
   scanf("%d", &n);
return (n);
}
	
int devuelve (int n){
   int a;
   int b;
   
   b=(int)pow(10, n);
   
   a=rand()%(b-1)+1;
   
	return (a);
}

char pregunta (int *a, int *b, int op) {

   int contesta;
   char valida;
   char conector[3]={'+','-','*'};
   int combina=0;
   int i;
   
   if(op==4){
   op=(rand()%3)+1;
   }
   printf("¿Cuánto es %d %c %d?: ", *a, conector[op-1], *b);
   scanf("%d", &contesta);
   switch(op){
   case 1:
   if(contesta==(*a)+(*b)){
   valida='v';
   }
   else{
   valida='f';
   }
   break;
   case 2: 
   if(contesta==(*a)-(*b)){
   valida='v';
   }
   else{
   valida='f';
   }
   break;
   case 3:
   if(contesta==(*a)*(*b)){
   valida='v';
   }
   else{
   valida='f';
   }  
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
