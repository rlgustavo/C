/*	JOGOS NA2- ENTREGA N1A- GRUPO 4:
(Gustavo Rocco Domingos)
(Gustavo Rodrigues de Lima)
(Andre Alves do Nascimento)
(Beatriz Cristina Campos Francisco)

Desenvolva um programa que leia do teclado um número inteiro e mostre na tela se esse número é primo ou não.
	 Lembrando: um número primo é divisível somente por 1 e por ele mesmo.
*/

#include<stdio.h>


int main()
{
	int num1;
	int i;
	int numPrimo = 0;
	
	printf("Digite um numero: ");
	scanf("%d", &num1);
	
	for (i=1; i<=num1; i++){
		if (num1 % i == 0)
			numPrimo++;
	}
	if (numPrimo == 2){
		printf("esse numero %d e um numero primo", num1);		
	}
	else{
		printf("esse numero %d nao e um numero primo", num1);
	}
	printf("\n\nFim do Programa");
}
