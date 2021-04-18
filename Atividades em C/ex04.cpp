/* JOGOS NA2- ENTREGA N1A- GRUPO 4:
(Gustavo Rocco Domingos)
(Gustavo Rodrigues de Lima)
(Andre Alves do Nascimento)
(Beatriz Cristina Campos Francisco)*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>

int main(){
	int Min, Max;
	int chute;
	int intervalo;
	
	FILE *Arq;
	Arq = fopen("PALPITES.TXT","w");
	fprintf(Arq, "Numeros escolhidos para palpite\n\n");
	
	printf("Digite um valor Min: ");
	scanf("%d", &Min);
	
	do{
		printf("Digite um valor Max: ");
		scanf("%d", &Max);
		if(Max <= Min + 100)
			printf("valor invalido, O Maximo deve ser maior que Min + 100\n\n ");		
	} while(Max <= Min + 100);
	
	srand(time(NULL));
	intervalo = Min + rand() % (Max - Min);
	
	printf("O computador escolheu um numero aleatorio, tente descobrir\n");
	while(true){
		printf("Chute um numero entre Min e Max: ");
		scanf("%d", &chute);		
		fprintf(Arq,"%d\n", chute);
			
		if(chute > intervalo)
			printf("\nSeu chute %d foi Maior que o numero sorteado \n", chute);
		else if(chute < intervalo)
			printf("\nSeu chute %d foi Menor que o numero sorteado \n", chute);
		else{
			printf("Voce Acertou!!");
		break;
		}
	}
	printf("\n\nFim do Programa ");
}
