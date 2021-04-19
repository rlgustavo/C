/* escreva um programa que leia um numero inteiro e
	mostre na tela se ele é positivo, negativo ou zero
	CASO SEJA POSITIVO DEVE CALCULAR X * 3
	CASO SEJA NEGATIVO DEVE CALCULAR Y = -(X) * 2
	SE FOR 0 NÃO FAÇA NADA
*/

#include<stdio.h>


int main()
{
	int X, Y;
	
	printf("Digite X: ");
	scanf("%d", &X);
	
	if (X > 0)
	{
		printf("%d = positivo", X);
		Y = X * 3;
		printf("\nY = %d", Y);
	}
	else if (X < 0)
	{
		printf("%d = negativo", X);
		Y = -X * 2;
		printf("Y = %d", Y);
	}
	
	printf("\n\nFim do Programa");
}
