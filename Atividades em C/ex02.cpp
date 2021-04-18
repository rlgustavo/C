/* JOGOS NA2- ENTREGA N1A- GRUPO 4:
(Gustavo Rocco Domingos)
(Gustavo Rodrigues de Lima)
(Andre Alves do Nascimento)
(Beatriz Cristina Campos Francisco)

*/

#include<stdio.h>
#include<stdlib.h>


int main(){
	int *V;
	int Min, Max;
	int i, X, Z;
	int Qtde = 0;

	FILE *Arq;
	
	Arq = fopen("PRIMOS.txt","w");
	fprintf(Arq, "Numeros Primos\n\n");
	
	V = (NULL);
	
	do{	
		printf("Digite um valor Min: ");
		scanf("%d", &Min);
		if (Min <= 1){
			printf("numero invalido Digite novamente\n\n");
		}

	} while (Min <= 1);
	
	do{	
		printf("Digite um valor Max: ");
		scanf("%d", &Max);
		if (Max <= Min){
			printf("numero invalido Digite novamente\n\n");
		}
	} while (Max <= Min);

	X = Min;	
	while(X < Max){
		Z = 0;
		for(i = 1; i < X; i++)
			if(X % i == 0){
				Z++;
			}
		if(Z == 1){
			Qtde++;
			V = (int *) realloc(V,sizeof(int) * Qtde);
			V[Qtde-1]= X;
			fprintf(Arq,"%d\n", X);
		} 
	X++;
	}
	for(i = 0; i < Qtde; i++){
		printf("%d ", V[i]);
	}
		
	free(V);
}






	
	



	
	
	
	

