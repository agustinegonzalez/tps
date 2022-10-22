#include <stdio.h>

int main() {
	
	int codigodepago = 0;
	int horas;
	int articulos;
	float salariosemanal;
	float salarioporhora;
	float ventasbrutassemanales;
	float pagoporarticulo;
	float pagototal;

	
	printf ("1. Gerentes\n2. Trabajadores por hora\n3. Trabajadores de comision\n4. Trabajadores a destajo");
	printf ("\n\nIntroduza el codigo de pago para el empleado elegido (-1 para salir): ");
		scanf ("%d", &codigodepago);
	
		
	while ( codigodepago != -1 )
	{
		switch (codigodepago)
		{
		case 1:
			printf ("\nIntroduzca el salario semanal de este gerente: ");
				scanf ("%f", &salariosemanal);
			pagototal = salariosemanal;
			break;
		case 2:
			printf ("\nIntroducta el salario por hora de este trabajador por hora: ");
			scanf ("%f", &salarioporhora);
			printf ("\nIntroduzca las horas trabajadas: ");
			scanf ("%d", &horas);
			if ( horas <= 40 )
				pagototal = horas * salarioporhora;
			else //horas extra
				pagototal = (40 * salarioporhora) + ((horas - 40) * salarioporhora * 1.5);
			break;
		case 3:
			printf ("\nIntroduzca ventas brutas para este trabajador a comision: ");
			scanf ("%f", &ventasbrutassemanales);
			pagototal = 250 + (ventasbrutassemanales * 0.057);
			printf ("\nPago total: %.2f", pagototal);
			break;
		case 4:
			printf ("\nIntroduzca el número de artículos producidos para este trabajador a destajo: ");
			scanf ("%d", &articulos);
			printf ("\nIntroduzca el pago por cada articulo: ");
			scanf ("%f", &pagoporarticulo);
			pagototal = articulos * pagoporarticulo;
			break;
		default:
			printf ("\nNo esta registrado dicho empleado");
			pagototal = 0;
			break;
		}
		printf ( "\nLa paga total de la semana es: %.2f", pagototal);
		printf ( "\n\nIntroduzca el codigo de pago para el empleado elegido (-1 para salir): ");
		scanf ("%d", &codigodepago);
	}
	
	return 0;
}

