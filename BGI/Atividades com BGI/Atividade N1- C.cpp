/* JOGOS NA2- ENTREGA N1A- GRUPO 4:
(Gustavo Rocco Domingos)
(Gustavo Rodrigues de Lima)
(Andre Alves do Nascimento)
(Beatriz Cristina Campos Francisco)*/

#include<stdio.h>
#include<graphics.h>
#include<time.h>

#define ESC 27
#define tam	5

struct TBolinhas {
	int x, y;
	int raio;
	int cor;
	int passoX, passoY;
};

struct circuloPreenchido {
		int x, y, raio1, raio2;
};

struct circuloVazado {
	int x, y, raio1;
};

struct retanguloPreenchido{
	int left, top, right, bottom; 
};

struct retanguloVazado{
	int left, top, right, bottom; 
};


void indoProLado (int x, retanguloPreenchido retP, int width, int height, int corBorda, int i, int dx, int dy, retanguloVazado retV, circuloVazado cirV) {
	//grama
	setlinestyle(0, 1, 1);
	setfillstyle(1, RGB(0, 255, 0));
	bar(retP.left+0+x, retP.top+width, retP.right+height+x, retP.bottom+400);
	
	int vetorPoly[10] = {250+x, 80, 280+x, 110, 280+x, 140, 220+x, 140, 220+x, 110};
	int vetorPoly2[10] = {50+x, 199, 50+x, 169, 100+x, 139, 150+x, 169, 150+x, 199};
	
	srand(time(NULL));
	for (i = 0; i <= 1000; i++) {
		dx = rand() % width+x;
		dy = rand() % height-100;
		putpixel(dx, dy, RGB(rand()% 256, rand()% 256,rand()% 256));			
	}

// retangulo Preenchido Preto
	setcolor(RGB(0, 0, 0));	
	setfillstyle(1, RGB(0, 0, 0));
	
	bar(retP.left+50+x, retP.top+200, retP.right+150+x, retP.bottom+400);


// Borda do Retangulo Preto	


	rectangle(retP.left+50+x, retP.top+200, retP.right+150+x, retP.bottom+400);		
// Teto do Predio Preto
	setfillstyle(1, RGB(255, 107, 70));
	fillpoly(5, vetorPoly2);

// Janelas Predio Preto
	setcolor(RGB(255, 255, 255));
	rectangle(retV.left+75+x, retV.top+380, retV.right+95+x, retV.bottom+400);
	rectangle(retV.left+105+x, retV.top+380, retV.right+125+x, retV.bottom+400);
	rectangle(retV.left+75+x, retV.top+300, retV.right+95+x, retV.bottom+350);
	rectangle(retV.left+105+x, retV.top+300, retV.right+125+x, retV.bottom+350);
	rectangle(retV.left+75+x, retV.top+220, retV.right+95+x, retV.bottom+250);
	rectangle(retV.left+105+x, retV.top+220, retV.right+125+x, retV.bottom+250);
	
// Maçaneta

	circle(cirV.x+90+x, cirV.y+395, cirV.raio1+2);
	circle(cirV.x+120+x, cirV.y+395, cirV.raio1+2);
	
			
	setfillstyle(1, RGB(28,28,28));
	bar(220+x, 140, 280+x, 400);
	
	setfillstyle(1, RGB(169, 169, 169));
	fillellipse(400+x, 100, 55, 55);
	
	setfillstyle(1, RGB(192,192,192));
	fillellipse(430+x, 90, 5, 5);
	
	setfillstyle(1, RGB(211,211,211));
	fillellipse(360+x, 90, 10, 10);
	

	setfillstyle(1, RGB(220,220,220));
	fillellipse(390+x, 130, 7, 7);
	circle(cirV.x+390+x, cirV.y+130, cirV.raio1+7);
	circle(cirV.x+430+x, cirV.y+90, cirV.raio1+5);
	circle(cirV.x+360+x, cirV.y+90, cirV.raio1+10);
	
	setfillstyle(9, RGB(165, 107, 70));
	fillpoly(5, vetorPoly);
	
	for ( i = 0; i < 12; i++){
		setcolor(RGB(rand() % 100, rand() % 100, rand() % 100));
	setlinestyle(1, 2, 2);
	line(85-i*5+x, 405+i*4, 110+i*5+x, 405+i*4);
	}
}


int main() {
	char tecla = 0;
	int pg;
	int corBorda;
	int x, y, raio, cor, passoX, passoY;
	int dx, dy, i, j;
	int width, height;
	TBolinhas *B;
	
	circuloPreenchido cirP;
	cirP.x = 0;
	cirP.y = 0;
	cirP.raio1 = 0;
	cirP.raio2 = 0;

	circuloVazado cirV;
	cirV.x = 0;
	cirV.y = 0;
	cirV.raio1 = 0;
	
	retanguloPreenchido retP;
	retP.left = 0;
	retP.top = 0;
	retP.right = 0;
	retP.bottom = 0;
	
	retanguloVazado retV;
	retV.left = 0;
	retV.top = 0;
	retV.right = 0;
	retV.bottom = 0;
  	
  	srand(time(NULL));
	corBorda = RGB(255, 0, 0);
	
  	B = (TBolinhas *)malloc(sizeof(TBolinhas) * tam);
  	for (i = 0; i < tam; i++) {
  		B[i].x = 205;
  		B[i].y = 205;
  		B[i].raio = 15;
  		B[i].cor = RGB(rand()% 256, rand()% 256,rand()% 256);
  		B[i].passoX = rand() % 9 - 4;
		B[i].passoY = rand() % 9 - 4;
	  }
	
	printf("Informe o valor da dimensao horizontal da tela: ");
	scanf("%i",&width);
	printf("Informe o valor da dimensao vertical da tela: ");
	scanf("%i",&height);
  	initwindow(width, height, "ExPgm02", 500, 100);
  	setbkcolor(RGB(20, 20, 	83));
  	cleardevice();
  	
  	
  	while(tecla != ESC) {
		if (pg == 1) 
			pg = 2; 
		else 
			pg = 1;
			
	    setactivepage(pg);
		cleardevice();
					
		indoProLado (x, retP, width, height, corBorda, i, dx, dy, retV, cirV);
		indoProLado (x + height, retP, width, height, corBorda, i, dx, dy, retV, cirV);
		x++;
		if (x == height)
			x = 0;
		
		
		//borda
		setcolor(corBorda);
		setlinestyle(0, 1, 1);
		rectangle(10, 10, width-10, height-10);
		
		for (i = 0; i < tam; i++){
			setcolor(B[i].cor);
			setfillstyle(1, B[i].cor);
			fillellipse(B[i].x, B[i].y, B[i].raio, B[i].raio);
		}		
		setvisualpage(pg);
		
	    for (i = 0; i < tam; i++) {
	    	B[i].x = B[i].x + B[i].passoX;
	    	B[i].y = B[i].y + B[i].passoY;
	    	if (B[i].x-B[i].raio < 10 || B[i].x+B[i].raio > width - 10)
	      		B[i].passoX = -B[i].passoX;
	      
	    	if (B[i].y-B[i].raio < 10 || B[i].y+B[i].raio > height - 10)
	      		B[i].passoY = -B[i].passoY;   
		}	
	    
	
	    delay(20);
	    fflush(stdin);
	    if (kbhit())
	      tecla = getch();   
  	}

	

  closegraph();
  free(B);
  return(0);

}
	
