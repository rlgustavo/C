/* Escreva um programa que mostre na tela os termos de uma progressão aritmética (pa).
	sendo dados de entrada:
	primeiro termo / razão / quantidade a ser exibida
	exemplo
	
	primeiro termo = 3
	razão = 4
	quantidade de termos = 6
	PA = 3 7 11 15 19 23
*/

#include<stdio.h>


int main()
{
	int P, R, Qtde, i, termo;
	
	printf("digite o primeiro termo: ");
	scanf("%d", &P);
	
	printf("\ndigite a razao: ");
	scanf("%d", &R);
	
	printf("\ndigite a Quantidade: ");
	scanf("%d", &Qtde);
	
	printf("PA produzida com comando while: ");
	
	termo = P;
	i = 0;
	while (i < Qtde)
	{
		printf("%d", termo);
		termo = termo + R;
		i++;
	}
	
	for (i = 0; i < Qtde; i++)
	{
		printf("%d", termo);
		termo = termo + R;
		i++;
	}
	
	printf("\n\nFim do Programa");
}
