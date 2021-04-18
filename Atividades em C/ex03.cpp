/* JOGOS NA2- ENTREGA N1A- GRUPO 4:
(Gustavo Rocco Domingos)
(Gustavo Rodrigues de Lima)
(Andre Alves do Nascimento)
(Beatriz Cristina Campos Francisco)*/

#include<stdio.h>
#include<stdlib.h>

void ExibeVetor(int *pVetor, int pTam) {
	int i, j, aux;
	printf("Elementos do Vetor dinamico\n");
				
	for (i = 0; i < pTam; i++) {	
		for(j = i + 1; j < pTam; j++){
			if(pVetor[i] < pVetor[j]){
					
				aux = pVetor[i];
				pVetor[i] = pVetor[j];
				pVetor [j] = aux;			
			}
		}
	}
	// Se quiser que todos os Numeros do Arquivos sejam Organizados
	for(i = 0; i < 5; i++){ // Basta Trocar ( i < 5; ) para ( i < pTam; )
		printf("%d\n", pVetor[i]);			
	}
}

int main(){
	int *vetor;
	int qtde;
	int x;
	
	FILE *arq;
	arq = fopen("SCORES.TXT", "r");
	if(arq == NULL) {
		printf("O arquivo nao existe");
		return 0;
	}
	
	qtde = 0;
	vetor = NULL;
	while (fscanf(arq, "%d", &x) != EOF) {
		qtde++;	
		vetor = (int *)realloc(vetor, sizeof(int) * qtde);	
		vetor[qtde-1] = x;
	}
	
	ExibeVetor(vetor, qtde);
	
	free(vetor);
	printf("\n\nFim do Programa ");
}
