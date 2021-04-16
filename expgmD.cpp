/* JOGOS NA2- ENTREGA N1A- GRUPO 4:
(Gustavo Rocco Domingos)
(Gustavo Rodrigues de Lima)
(Andre Alves do Nascimento)
(Beatriz Cristina Campos Francisco)*/


#include<stdio.h>
#include<graphics.h>
#include<time.h>

#define ESC 	27
#define LEFT	75
#define RIGHT	77
#define UP		72
#define DOWN	80

struct tStars{
	int starX, starY;
	int starC;
	int grandeza;
};

void desenho(int*a) {
	setlinestyle(0,0,3);
	setcolor(5);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(4,a);
	setlinestyle(0,0,1);
}

void up (int*a,int*passo){
	for(int i = 1;i<8;i+=2){
		a[i]-=*passo;
	}
}

void down (int*a,int*passo){
	for(int i = 1;i<8;i+=2){
		a[i]+=*passo;
	}
}

void left (int*a,int*passo){
	for(int i = 0;i<7;i+=2){
		a[i]-=*passo;
	}
}

void right (int*a,int*passo){
	for(int i = 0;i<7;i+=2){
		a[i]+=*passo;
	}
}

void limites(int*a,int*xt,int*yt){
	if(a[1]<0){
		a[1] = 0;
		a[3] = a[1]+30;
		a[5] = a[1]+30;
		a[7] = a[1];
	}
	if(a[2]>*xt){
		a[0] = *xt-100;
		a[2] = a[0]+100;
		a[4] = a[0]-100;
		a[6] = a[0];
	}
	if(a[4]<0){
		a[0] = 100;
		a[2] = a[0]+100;
		a[4] = a[0]-100;
		a[6] = a[0];
	}
	if(a[3]>*yt){
		a[1] = *yt-30;
		a[3] = a[1]+30;
		a[5] = a[1]+30;
		a[7] = a[1];	
	}
}

int main()  {
	char tecla = 0;
	int tamX, tamY;
	int qtdeEstrela, tamEstrela, tamEstrela2;
	int i, x, y, j, cont;
	int passo = 15;
	int pg = 0;
	bool brilhoEstrela = true;
	bool salto = false;

	tStars *estrelas;
	tStars xG;

	xG.grandeza = 1;	
	cont = 0;
	j = 0;

	 	
	printf("Digite o Tamanho Horizontal da Tela: ");
	scanf("%d", &tamX);
	
	tamY = tamX/3 * 2;
	qtdeEstrela = .008*(tamX*tamY);
	tamEstrela = qtdeEstrela/5;
	tamEstrela2 = tamEstrela/5;
	
	x = tamX/2;
	y = tamY-50;
	int nave[8] = {x, y, x+100, y+30, x-100, y+30, x, y};
	
	estrelas = NULL;
	printf("essa foi a tamanho de tamX | %d |\n", tamX);
	printf("essa foi a tamanho de tamY | %d |\n", tamY);
	printf("essa foi a quantidade de estrelas | %d |", qtdeEstrela);



	initwindow(tamX, tamY, "exercicio D", 100, 100);
	
	srand(time(NULL));
	estrelas = (tStars *)realloc(estrelas, sizeof(tStars) * qtdeEstrela);

	for (i = 0; i < qtdeEstrela; i++){
		estrelas[i].starX = rand() % tamX + 1;
		estrelas[i].starY = rand() % tamY + 1;
		estrelas[i].starC = RGB(rand() % 200+56, rand() % 200+56, rand() % 200+56);	
	}

	while(tecla != ESC){
		
		setactivepage(pg);
		setvisualpage(1-pg);
		
		cleardevice();
		
		if (salto == true){
			j++;
			if (j == 100){
				for (i = 0; i < qtdeEstrela; i++){
					estrelas[i].starX = rand() % tamX + 1;
					estrelas[i].starY = rand() % tamY + 1;
					estrelas[i].starC = RGB(rand() % 200+56, rand() % 200+56, rand() % 200+56);	
				}
				salto = false;
				j = 0;	
			}
		}
		for (i = 0; i < qtdeEstrela; i++){
			putpixel(estrelas[i].starX, estrelas[i].starY, estrelas[i].starC);	
		}
		for (i = 0; i < tamEstrela; i++){
			setcolor(estrelas[i].starC);
			setfillstyle(SOLID_FILL, estrelas[i].starC);
			fillellipse(estrelas[i].starX, estrelas[i].starY, xG.grandeza, xG.grandeza);
		}	
		if(brilhoEstrela){
			if (cont<20){
				for(int i = tamEstrela; i< tamEstrela+tamEstrela2; i++){
					setcolor(estrelas[i].starC);
					setfillstyle(SOLID_FILL, estrelas[i].starC);
					fillellipse(estrelas[i].starX, estrelas[i].starY, xG.grandeza+1, xG.grandeza+1);	
					}
				}
				else{
					for(int i = tamEstrela; i< tamEstrela+tamEstrela2; i++){
						setcolor(estrelas[i].starC);
						setfillstyle(SOLID_FILL, estrelas[i].starC);
						fillellipse(estrelas[i].starX, estrelas[i].starY, xG.grandeza+2, xG.grandeza+2);	
					}
				}
				cont++;
				if (cont>35){
					cont = 0;
				}
		}		
		desenho(nave);
		if(GetKeyState(VK_LEFT)&0x80){
			left(nave, &passo);
		}
	    if(GetKeyState(VK_RIGHT)&0x80){
	    	right(nave, &passo);
		}
	    if(GetKeyState(VK_UP)&0x80){
	    	up(nave, &passo);
		}
	    if(GetKeyState(VK_DOWN)&0x80){
	    	down(nave, &passo);
		}
		
		if(kbhit()){
			if(GetKeyState(VK_SPACE)&0x80) {
				nave[0] = 100+rand()%((tamX-99)-100);
				nave[1] = rand()%(tamY-29);
				nave[2] = nave[0]+100;
				nave[3] = nave[1]+30;
				nave[4] = nave[0]-100;
				nave[5] = nave[1]+30;
				nave[6] = nave[0];
				nave[7] = nave[1];
					
			}
			if (GetKeyState(0x56)&0x80){
				for (int i = 0; i < qtdeEstrela; i++){
					estrelas[i].starX = rand() % tamX + 1;
					estrelas[i].starY = rand() % tamY + 1;
					estrelas[i].starC = RGB(rand() % 200+56, rand() % 200+56, rand() % 200+56);	
				}
			}
			if (GetKeyState(0x53)&0x80){
				if (j == 0 )
					for (int i = 0; i < qtdeEstrela; i++){
						estrelas[i].starX = rand() % tamX + 1;
						estrelas[i].starY = rand() % tamY + 1;
						estrelas[i].starC = RGB(32, 39, 54);
					}
				salto = true;
			}	
		}
		limites(nave, &tamX, &tamY);
		pg = 1 - pg;
		
	}
	free(estrelas);	
	getch();
	closegraph();
	return(0);
}
