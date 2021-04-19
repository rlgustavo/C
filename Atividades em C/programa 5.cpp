/* escreva um programa que leia um numero inteiro e
	mostre na tela se ele é positivo, negativo ou zero
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int X;
	
	printf("Digite X: ");
	scanf("%d", &X);
	
	if (X > 0)
	{
		printf("%d = positivo", X);
	}
	else if(X == 0)
	{
		printf("%d = Igual a 0", X);
	}
	else
	{
		printf("%d = negativo", X);
	}
	
	printf("\n\nFim do Programa");
}
