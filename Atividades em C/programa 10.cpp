/* Escreva um programa que leia os coeficientes A, B e C  de uma equação
	do segundo grau e mostre na tela as raízes dessa equação
*/

#include<stdio.h>
#include<math.h>

int main()
{
	double A, B, C, Delta, x1, x2;
	
	printf("Forneca A: ");
	scanf("%lf", &A);
	printf("\nForneca B: ");
	scanf("%lf", &B);
	printf("\nForneca C: ");
	scanf("%lf", &C);
	
	if (A == 0)
	{
		printf("A = 0, então não temos uma equacao do segundo grau");
	}
	else
	{
		Delta = B*B - 4*A*C;
		if (Delta > 0)
		{
			x1 = (-B - pow(Delta, 0.5)) / (2 * A);
			x1 = (-B + pow(Delta, 0.5)) / (2 * A);
			printf("x1 = %.3lf e x2 = %.3lf", x1, x2);
		}
		else if (Delta == 0)
		{
			x1 = -B / (2 * A);
			printf("x1 = x2 = %.3lf", x1);
		}
		else
		{
			printf("Nao existem raizes reais");
		}
	}
	printf("\n\nFim do Programa");
}
