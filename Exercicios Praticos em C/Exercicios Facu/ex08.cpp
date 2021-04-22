//JOGOSNA2 -  ENTREGA N1 . A - Grupo 4

#include<stdio.h>
#include<math.h>

int main()
{
	int A, B, potencia;
	int divI;
	double divR;
	
	printf("\nDigite A: ");
	scanf("%d", &A);
	
	printf("\nDigite B: ");
	scanf("%d", &B);
	
	printf("Soma = %d\n", A + B);
	printf("Subtracao = %d\n", A - B);
	printf("Divisao = %d\n", A / B);
	printf("multiplicacao = %d\n", A * B);
	
	divI = A / B;
	printf("divisao (como inteiro) = %d\n", divI);
	
	divR = (double)A / B;
	printf("divisao (como double) = %lf\n\n", divR);


	potencia = pow(A, B);
	printf("potencia = %d\n\n\n", potencia);

	
	printf("Fim do Programa 2\n\n");
}
