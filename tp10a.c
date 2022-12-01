#include <stdio.h>

union u
{
	unsigned int i;
	float f;
};

void imprimirdatos();
void signo(union u u1);
void exponente(union u u1);
void mantisa (union u u1);

int main()
{
	union u u1;
	int pos;
	
	printf("Ingrese un flotante: ");
	scanf("%f",&u1.f);
	
	for(pos=31;pos>=0;pos--)
	{
		printf("%d",u1.i>>pos&1);
		pos==31? printf(" | "):
		pos==23? printf(" | "):printf("%c", 00);
	}
	printf("\n");	

  imprimirdatos(u1);
      
	return 0;
}

void imprimirdatos(union u u1){

  int sign=u1.i>>31;
  printf("Bit de signo: ");
  signo(u1);printf(" (%d)\n", sign);
  
  int exp=(u1.i<<1)>>24;
  printf("Bits del exponente: ");
  exponente(u1); printf(" (%d)\n", exp);
  
  int manti=(u1.i<<9)>>9;
  printf("Bits de la mantisa: ");
  mantisa(u1);printf(" (%d)\n", manti);
	  
}

void signo(union u u1){
  printf("%d", u1.i>>31&1);
}

void exponente(union u u1){
  int pos;
  for(pos=30;pos>=23;pos--)
		printf("%d",u1.i>>pos&1);
}

void mantisa (union u u1){
  int pos;
  for(pos=22;pos>=0;pos--)
		printf("%d",u1.i>>pos&1);
}
