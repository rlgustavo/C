#include<stdio.h>
#include<graphics.h>

#define ESC 27

int main() {
  char tecla = 0;
  int pg;
  int corBorda;
  int x, y, raio, cor, passoX, passoY;
  
  corBorda = RGB(255, 0, 0);
  
  x = 260;
  y = 200;
  raio = 15;
  cor = RGB(255, 255, 0);
  passoX = 2;
  passoY = 1;

  initwindow(410, 410, "Movimentos - Exemplo 3", 500, 200);
  while(tecla != ESC) {
    // Desenho da tela no estado atual
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);  // Onde Desenho
    cleardevice();
    setcolor(corBorda);
    rectangle(10, 10, 400, 400);
    setcolor(cor);
    setfillstyle(1, cor);
    fillellipse(x, y, raio, raio);
    setvisualpage(pg);  // Torna visual a pg que acaba de ser desenhada

    // Cálculo do novo estado
    x = x + passoX;
    y = y + passoY;
    if (x-raio < 10 || x+raio > 400)
      passoX = -passoX;
      
    if (y-raio < 10 || y+raio > 400)
      passoY = -passoY;    

    delay(50);
    fflush(stdin);
    if (kbhit())
      tecla = getch();   
  }


  closegraph();
  return(0);

}
