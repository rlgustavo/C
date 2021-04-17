#include<stdio.h>
#include<graphics.h>

int main()  { 
	initwindow(600, 500, "Fatec's in Luv", 100, 100);
	setbkcolor(WHITE);
	cleardevice;
	
	readimagefile("teste.jpg", 100, 100, 300, 300);
	
	
	
	getch();	
	closegraph();	
}
