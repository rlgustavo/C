#include<stdio.h>
#include<graphics.h>

int main()  { 
	initwindow(1200, 780, "Fatec's in Luv", 0, 0);
	setbkcolor(WHITE);
	cleardevice;
	
	readimagefile("teste.jpg", 0, 0, 1200, 780);

	
	
	getch();	
	closegraph();	
}
