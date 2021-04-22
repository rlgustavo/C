/* escreva um programa que leia dois números inteiros
	calcule e mostre na tela a soma dos dois apenas se ambos forem positivos ou zero
	se for negativo return dados inconsstentes
*/

#include<stdio.h>


int main()
{
	int A, B, soma;
	
	printf("digite A: ");
	scanf("%d", &A);
	
	printf("\ndigite B: ");
	scanf("%d", &B);
	
	if (A >= 0 && B >= 0 || A <= 0 && B <= 0)
	{
		soma = A + B;
		printf("soma de %d com %d =  %d", A, B, soma);
	}
	else
		printf("Dados inconsistentes");
			
	printf("\n\nFim do Programa");
}
