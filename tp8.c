#include <stdio.h>
#include <stdlib.h>


void pide (int[][10], char *[5]);
void muestra(char *[5], int [5][10]);
int alto(int [5][10], char *[5]);
int bajo(int [5][10], char *[5]);

int main()
{
   char *causas[5]={"Economía","Seguridad","Educación","Tecnología","Desarrollo"};
   int contador[5][10]={{0},{0}};
   
   pide(contador, causas);
   muestra(causas, contador);
   alto(contador, causas);
   bajo(contador, causas);
   
return 0;
}

void pide (int contador [][10], char *causas[])
{
  int puntua;
   
  for(int j=0; j<10; j++){
    printf("Integrante [%d]: \n\n", j+1);
      
    for(int i= 0; i < 5; i++){
      printf("¿Qué tan importante es para usted?: %s (1 al 10)\n", causas[i]);
      do{
        scanf("%d", &puntua);
        if(!(puntua>0&&puntua<11)){
          printf("Ingrese un numero dentro del rango.\n");
        }
      }while(!(puntua>0&&puntua<11));
        
      contador[i][j]=puntua;
    }
  }
}

void muestra(char *causas[], int contador[][10])
{
   float promedio;
   
  printf("\t");
    
  for(int k=0; k<10; k++){
    printf("\t%d", k+1);
  }
  printf("\n\n");
  
   //muestra cuadro
  for(int i = 0; i < 5; i++){
    printf("%s", causas[i]);
    promedio=0;
    for (int j=0; j < 10; j++){
      printf("\t%d  |", contador[i][j]);
    }
      for(int k=0; k<10; k++){
        promedio+= contador[i][k];
      }
    promedio= (float)promedio/10;
    printf("\tPromedio: %f\n", promedio);
    printf("\n");
  }
}

int alto(int contador[][10], char *causas[]){
  int alto[5]={0};
  int max=0;
  int pos=0;
  
  for(int i=0; i<5; i++){
    for(int j=0; j<10; j++){
      alto[i]+=contador[i][j];
    }
  }
  
  for(int i=0; i<5; i++){
    if(alto[i]>max){
      max=alto[i];
      pos=i;
    }
  }
  
  printf("La causa que tiene mayor puntaje es: %s y la cantidad de "
  "puntaje es %d""\n\n", causas[pos], max);
}

int bajo(int contador[][10], char *causas[])
{
  int bajo[5]={0};
  int min=50;
  int pos=0;
  
  for(int i=0; i<5; i++){
    for(int j=0; j<10; j++){
      bajo[i]+=contador[i][j];
    }
  }
  
  for(int i=0; i<5; i++){
    if(bajo[i]<min){
      min=bajo[i];
      pos=i;
    }
  }
  
  printf("\nLa causa que tiene menor puntaje es: %s y la cantidad de puntaje es %d\n\n", causas[pos], min);
  
}  

