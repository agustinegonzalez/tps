#include <stdio.h>
#define FILAS 3 //incognitas
#define COLUMNAS 4 //incognita + columna de termino independiente


int main() {
	
	float matriz [FILAS][COLUMNAS];
	int i, j, k;

	for(i=0; i < FILAS; i++)
	{
		for(j = 0; j < COLUMNAS; j++)
		{
			printf("Introduzca los elementos de la columna [%d] fila [%d]: ", j+1, i+1);
			scanf( "%f", &matriz [i][j]);
		}
	}
	
	for(i=0;i<FILAS;i++)
	{
		if(matriz[i][i]==0)
		{
			printf("\nError: Introdujo un cero. Escriba un sistema valido.\n");
			break;
		}
	
		//muestra de matriz
		for(i=0; i < FILAS; i++ )
		{
			for(j=0; j < COLUMNAS; j++ )
			{
				printf ( "%.2f  ", matriz [i][j] );
			}
			printf("\n");
		}
		
		//calculos
		for(int i=0; i < FILAS; i++ ) 
		{
			for ( j = COLUMNAS-1; j >= 0; j-- )
			{ 
				matriz [i][j] = matriz [i][j] / matriz [i][i]; //hace 1 la diagonal principal
			} 
			
			for ( k = i + 1; k <= FILAS-1; k++ )
			{
				for ( j = COLUMNAS-1; j >= 0; j-- )
				{
					matriz [k][j] = matriz[k][j] - (matriz [k][i] * matriz [i][j]); //hace 0 el triangulo inferior
				}
			}
			
			for(k = 0; k <= i-1; k++)
			{
				for(j=COLUMNAS-1; j >= 0; j-- )
				{
					matriz [k][j] = matriz [k][j] - (matriz [k][i] * matriz [i][j]);
				}
			}
		}
		
		//Mostrando resultado
		printf ( "\n" );
		for(i=0; i < FILAS; i++ )
		{
			printf ("%c= ",65+i);
			for(j=0; j < COLUMNAS-1; j++ )
			{
				printf ( "%.2f  ", matriz [i][j] );
			}
			printf ("= ");
			for(j=COLUMNAS-1; j < COLUMNAS; j++ )
			{
				printf ( "%.2f  ", matriz [i][j] );
			}
			
			printf ( "\n" );
		}
	}
	return 0;
}

