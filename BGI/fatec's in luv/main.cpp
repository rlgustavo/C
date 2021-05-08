/*
Função GetTickCount retorna o número de milissegundos transcorridos desde que o sistema operacional foi iniciado
Esta função tem uma precisão limitada a uma faixa entre 10 e 16 milisegundos, e isso depende das características
construtivas do processador do computador.
Essa função retorna um número inteiro grande, por isso seu retorno deve ser colocado em variável inteira 
de 64 bytes, sem sinal. Ou seja use o tipo "unsigned long long"

O retorno gerado por essa função é um inteiro sempre crescente. Para usar seus valores de retorno deve-se
calcular a diferença entre dois retornos capturados em momentos diferentes. Neste programa são usadas as
variáveis gt1 (primeiro momento) e gt2 (segundo momento).
A diferença entre ambas (gt2 - gt1) fornecerá o número de milissegundos transcorridos entre os dois 
momentos.

Para aplicar esse valor ao jogo, essa diferença deve ser comparada com o tempo de um frame em milissegundos.
A variável FPS contém o número de frames por segundo e o tempo de um frame é calculado pela fórmula
1000 / FPS

Assim, se gt2 - gt1 >= 1000 / FPS já transcorreu o tempo de um frame e o programa deve redesenhar a tela e
tratar as entradas do usuário.
Ao fazer isso, deve-se atualizar o valor de gt1 para o atual valor de gt2 (gt1 = gt2;) e o processo de 
contagem recomeça.

Dica: a precisão da função GetTickCount está limitada a 16 milissegundos, o frame rate de 60 FPS é o que mais 
      se arpoxima dessa precisão pois 1000/60 = 16,666666...
      
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
    if (gt2 - gt1 > 1000/FPS) { /* este if garante que o programa só desenhará no momento certo */
      gt1 = gt2;
      
      /* Executa desenho da tela */
      if (pg == 1) pg = 2; else pg=1;
      setactivepage(pg);
      /* Desenho do cenário */
      cleardevice();
      setcolor (LIGHTRED);
      rectangle(10, 10, 490, 490);
      /* Desenho dos elementos móveis */
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

      /* Trata entradas do usuário */
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


