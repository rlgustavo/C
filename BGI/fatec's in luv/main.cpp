/*
Fun��o GetTickCount retorna o n�mero de milissegundos transcorridos desde que o sistema operacional foi iniciado
Esta fun��o tem uma precis�o limitada a uma faixa entre 10 e 16 milisegundos, e isso depende das caracter�sticas
construtivas do processador do computador.
Essa fun��o retorna um n�mero inteiro grande, por isso seu retorno deve ser colocado em vari�vel inteira 
de 64 bytes, sem sinal. Ou seja use o tipo "unsigned long long"

O retorno gerado por essa fun��o � um inteiro sempre crescente. Para usar seus valores de retorno deve-se
calcular a diferen�a entre dois retornos capturados em momentos diferentes. Neste programa s�o usadas as
vari�veis gt1 (primeiro momento) e gt2 (segundo momento).
A diferen�a entre ambas (gt2 - gt1) fornecer� o n�mero de milissegundos transcorridos entre os dois 
momentos.

Para aplicar esse valor ao jogo, essa diferen�a deve ser comparada com o tempo de um frame em milissegundos.
A vari�vel FPS cont�m o n�mero de frames por segundo e o tempo de um frame � calculado pela f�rmula
1000 / FPS

Assim, se gt2 - gt1 >= 1000 / FPS j� transcorreu o tempo de um frame e o programa deve redesenhar a tela e
tratar as entradas do usu�rio.
Ao fazer isso, deve-se atualizar o valor de gt1 para o atual valor de gt2 (gt1 = gt2;) e o processo de 
contagem recome�a.

Dica: a precis�o da fun��o GetTickCount est� limitada a 16 milissegundos, o frame rate de 60 FPS � o que mais 
      se arpoxima dessa precis�o pois 1000/60 = 16,666666...
      
Links interessantes sobre o assunto
https://gameprogrammingpatterns.com/game-loop.html
https://www.programmersought.com/article/63534517367/
      
*/
#include<stdio.h>
#include<time.h>
#include<graphics.h>

#define ESC    	27

int main()
{
  int pg = 1;
  char tecla;
  int x, y, raio;
  int passox, passoy;
  int FPS;
  unsigned long long gt1, gt2;

  srand(time(NULL));
  tecla = 0;
  x = 40;
  y = 40;
  raio = 18; 
  passox = 3;
  passoy = 1;
  FPS = 1;

  initwindow(500, 500, "Exemplo de FrameRate", 100, 100);
  gt1 = GetTickCount();
  gt2 = gt1 * 2;
  while(tecla != ESC) {    
    if (gt2 - gt1 > 1000/FPS) { /* este if garante que o programa s� desenhar� no momento certo */
      gt1 = gt2;
      
      /* Executa desenho da tela */
      if (pg == 1) pg = 2; else pg=1;
      setactivepage(pg);
      /* Desenho do cen�rio */
      cleardevice();
      setcolor (LIGHTRED);
      rectangle(10, 10, 490, 490);
      /* Desenho dos elementos m�veis */
      setfillstyle(1, YELLOW);
      setcolor (YELLOW);      
      fillellipse(x, y, raio, raio);    
      setvisualpage(pg);

      x = x + passox;
      y = y + passoy;
      if (x >= 490-raio || x <= 10+raio+1)
        passox = -passox;
      if (y >= 490-raio || y <= 10+raio+1)
        passoy = -passoy;

      /* Trata entradas do usu�rio */
      if(GetKeyState(VK_SPACE)&0x80) {
        x = 250;
        y = 250;
      }
  
    }
    gt2 = GetTickCount();

    fflush(stdin);    
    if (kbhit())
      tecla = getch();
  }

  closegraph();
  return(0);
}


