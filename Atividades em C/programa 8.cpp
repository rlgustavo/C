/* Escreva um programa que permane�a em la�o lendo n�meors inteiros. O la�o deve terminar quando for digitado zero(0).
	para cada valor lido, exiba na tela se o n�mero � par ou impar
	NESSE PROGRMAA SER� USADO O COMANDO WHILE.
*/

#include<stdio.h>


int main()
{
	int A;
	
	printf("digite A: ");
	scanf("%d", &A);
	while (A != 0)
	{
		if (A % 2 == 0)
		{
			printf("%d = Par", A);
		}
		else
		{
			printf("%d = impar", A);
		}
	printf("\n\ndigite A: ");
	scanf("%d", &A);

	}
	
			
	printf("\n\nFim do Programa");
}
