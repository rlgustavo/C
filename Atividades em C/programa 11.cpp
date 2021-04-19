/* Faça um programa que aloque num vetor, valores negativos e negativos
*/


#include<stdio.h>
#include<stdlib.h>

int main() {
	double *a, *pos, *neg;
	int n, i;
	int qtdeNeg = 0;
	int qtdePos = 0;
	
	do {
		printf("Digite uma quantidade de elementos: ");
		scanf("%d", &n);
	} while (n < 1 || n > 50);
	
	a = (double *)malloc(sizeof(double) * n);

	neg = NULL;
	pos = NULL;
	
	printf("\n\nVamos separa-los em Negativos e Positivos\n");
	
	for (i = 0; i < n; i++ ){
		printf("Digite o elemento %d: ", i);
		scanf("%lf", &a[i]);
		
		if (a[i] >= 0) {
			qtdePos++;
			pos = (double *)realloc(pos, sizeof(double) * qtdePos);
			pos[qtdePos-1] = a[i];
			
		}
		else{
			qtdeNeg ++;
			neg = (double *)realloc(neg, sizeof(double) * qtdeNeg);
			neg[qtdeNeg-1] = a[i];
		}
	}
	
	printf("\nRESULTADOS\n");
	
	printf("Numeros positivos\n");
	for(i = 0; i < qtdePos; i++) {
		printf("%.2lf, ", pos[i]);
	}
	
	printf("\n\nNumeros negativos\n");
	for(i = 0; i < qtdeNeg; i++) {
		printf("%.2lf, ", neg[i]);
	}
	
	free(pos);
	free(neg);
	free(a);
	printf("\n\nFim do programa\n\n");
}
