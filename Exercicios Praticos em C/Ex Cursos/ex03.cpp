/*Gustavo Lima
Ex03.
	Peça ao usuário para digitar três valores inteiros e imprima a soma deles
*/

#include <stdio.h>

int main(){
	
	int num1, num2, num3;
	int resultado;
	
	printf("Digite o Primeiro valor: ");
	scanf("%d", &num1);
	
	printf("Digite o Segundo valor: ");
	scanf("%d", &num2);
	
	printf("Digite o Terceiro valor: ");
	scanf("%d", &num3);
	
	resultado = num1 + num2 + num3;
	
	printf("a soma de %d + %d + %d = %d", num1, num2, num3, resultado);
	
	
	return 0;
}
