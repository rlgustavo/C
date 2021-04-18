#include<stdio.h>
#include<graphics.h>

#define ESC   27
#define LEFT  75
#define RIGHT 77
#define UP    72
#define DOWN  80

int main() {
  char tecla = 0;
  int LarTela, AltTela;
  int LarJogo, AltJogo;
  int xIniJogo, yIniJogo;
  int pg;
  int corBorda;
  int x, y, raio, cor, passoX, passoY;
  
  corBorda = RGB(255, 0, 0);
  
  x = 260;
  y = 200;
  raio = 15;
  cor = RGB(255, 255, 0);
  passoX = 15;  // o passo foi fixado em 15 para um movimento mais rápido
  passoY = 15;
  
  LarTela = GetSystemMetrics(SM_CXSCREEN);
  AltTela = GetSystemMetrics(SM_CYSCREEN);
  LarJogo = LarTela - 30;
  AltJogo = AltTela - 100;
  xIniJogo = (LarTela - LarJogo) / 2;
  yIniJogo = (AltTela - AltJogo) / 2 - 30;

  initwindow(LarJogo, AltJogo, "Movimento Controlado com kbhit() - Exemplo 4", xIniJogo, yIniJogo);
  while(tecla != ESC) {
    // Desenho da tela no estado atual
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);  // Onde Desenho
    cleardevice();
    setcolor(corBorda);
    rectangle(10, 10, LarJogo-10, AltJogo-10);
    setcolor(cor);
    setfillstyle(1, cor);
    fillellipse(x, y, raio, raio);
    setvisualpage(pg);  // Torna visual a pg que acaba de ser desenhada

    // Aquisição da entrada do usuário
    fflush(stdin);
    if (kbhit()) {
      tecla = getch();
      //printf("%d\n", tecla);   caso queira ver o código numérico da tecla - não esquecer de habilitar o console
      if(tecla == LEFT)  x = x - passoX;
      if(tecla == RIGHT) x = x + passoX;
      if(tecla == UP)    y = y - passoY;
      if(tecla == DOWN)  y = y + passoY;
      
      if(tecla == 'A' || tecla == 'a')  x = x - passoX;
      if(tecla == 'D' || tecla == 'd')  x = x + passoX;
      if(tecla == 'W' || tecla == 'w')  y = y - passoY;
      if(tecla == 'S' || tecla == 's')  y = y + passoY;
    }


    // tratamento das colisões da bolinha com as bordas
    if (x+raio >= LarJogo-10)  // as quantidades fixas em 10 nas linhas a seguir dizem respeito à borda
      x = LarJogo-raio-10;
    if (x-raio-1 <= 10)
      x = 10+raio+1;
    if (y+raio >= AltJogo-10)
      y = AltJogo-raio-10;
    if (y-raio-1 <= 10)
      y = 10+raio+1;
 
    delay(5);
  }


  closegraph();
  return(0);

}
