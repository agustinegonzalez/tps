#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct HealthProfile{
  char nombre[30];
  char apellido[30];
  char sexo[20];
  struct fecha{
  int dia;
  int mes;
  int anio;
  }nacimiento;
  float altura;
  float peso;
};

void tomadatos(struct HealthProfile *info);
int f_edad(struct HealthProfile *info);
void cargaparabmi(struct HealthProfile *info);
float bmi(float a, float p);
int freqmax(int);
int rango1(int);
int rango2(int);

int main()
{
  int edad;  
  float imc;
  int frecuenciamaxima;
  
  struct HealthProfile registro;
  struct HealthProfile *pp;

  pp=&registro;
  tomadatos(pp);
  edad=f_edad(pp);
  cargaparabmi(pp);
  imc=bmi(registro.altura, registro.peso);
  frecuenciamaxima=freqmax(edad);
  
  printf("\n *El paciente -%s %s- de sexo -%s-, nacido el %d/%d/%d tiene una altura de %.2f metros y un peso ",registro.nombre, registro.apellido, registro.sexo, registro.nacimiento.dia, registro.nacimiento.mes, registro.nacimiento.anio, registro.altura);
  printf("de %.2f kilogramos.\n *Su edad es %d y tiene un IMC de %.1f\n", registro.peso, edad, imc);
  printf(" *La frecuencia cardíaca máxima es de %d y el rango de frecuencia cardíaca máxima oscila entre %d y %d\n",frecuenciamaxima, rango1(frecuenciamaxima), rango2(frecuenciamaxima));
  
return 0;
}


void tomadatos(struct HealthProfile *info)
{  
  printf("¿Cuál es su nombre?: ");
  scanf("%s", info->nombre);
  printf("¿Cuál es su apellido?: ");
  scanf("%s", info->apellido);
  printf("¿Cuál es su sexo?: ");
  scanf("%s", info->sexo); 
}

int f_edad(struct HealthProfile *info)
{
  int edad;
  
  time_t t;
  t = time(NULL);
  struct tm tm = *localtime(&t);
  
  printf("\nIngrese el dia, mes y año de nacimiento:\n");
  scanf("%d %d %d", &info->nacimiento.dia, &info->nacimiento.mes, &info->nacimiento.anio);
  
  edad=(tm.tm_year+1900) - (info->nacimiento.anio);
  if(tm.tm_mon+1 <= info->nacimiento.mes){
    if(tm.tm_mday < info->nacimiento.anio){
      return (edad-1);
    }
    else{
      return (edad);
    }
  }
}

void cargaparabmi(struct HealthProfile *info)
{
  printf("\n¿Cuál es su altura? (en metros): ");
  scanf("%f", &info->altura);
  printf("¿Cuál es su peso? (en kilogramos): ");
  scanf("%f", &info->peso);  
}

float bmi(float a, float p)
{
  float imc;
  
  imc=p/(a*a);

return imc;
}

int freqmax(int edad){
  return (220-edad);  
}

int rango1(int fmax){
  return (fmax * 0.5);
}
int rango2(int fmax){
  return (fmax * 0.85);
}

  
