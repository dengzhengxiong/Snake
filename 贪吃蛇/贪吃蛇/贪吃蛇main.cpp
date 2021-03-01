#include <iostream>
#include"show.h"
#include"food.h"
#include"unit.h"
#include"snake.h"
#include<conio.h>
#include"control.h"
#include <windows.h>
#pragma comment(lib,"winmm.lib")
int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cci);
	PlaySound(TEXT("E:\\ShortTheme1ThomasGreenberg.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	/*
	jiemian show1;
	show1.init();
	snake mySnake;
	food MyFood;
	MyFood.CreatPos();
	MyFood.show();
	while (_kbhit) 
	{
		mySnake.move();
		if (mySnake.eatFood(&MyFood))
		{
			mySnake.changesnake();
			MyFood.erase();
			MyFood.CreatPos();
			MyFood.show();
		}
	}*/
	control *mycontrol = new control();
	mycontrol->init();
	system("pause");
	return 0;
}