#include"show.h"
#include<iostream>
#include"unit.h"
#include<windows.h>
#include"snake.h"
jiemian::jiemian()
{
		HANDLE hOut;
		CONSOLE_SCREEN_BUFFER_INFO scr;

		hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
		GetConsoleScreenBufferInfo(hOut, &scr);
		m_coor.X = scr.srWindow.Right;
		m_coor.Y = scr.srWindow.Bottom;
}
jiemian::~jiemian()
{}
void jiemian::initi()
{
	for (int i =KLEFT ;i<= m_coor.X -3;i++)
	{
		unit::gotoxy(i, KLEFT);
		cout << "■";
	}
	for (int j=KUP;j<= m_coor.Y;j++)
	{
		unit::gotoxy(KUP, j);
		cout << "■";
	}
	for (int i = KLEFT; i <= m_coor.X -3; i++)
	{
		unit::gotoxy(i, m_coor.Y);
		cout << "■";
	}
	for (int j = KUP; j <= m_coor.Y; j++)
	{
		unit::gotoxy(m_coor.X -3,j);
		cout << "■";
	}
	for (int i = KLEFT; i <= m_coor.X - 3; i++)
	{
		unit::gotoxy(i, KLEFT+4);
		cout << "■";
	}
		unit::gotoxy(KLEFT+1, KLEFT + 2);
		cout << "游戏名称：贪吃蛇   ";
			cout << "作者：邓正熊   ";
		unit::gotoxy(m_coor.X/2, KLEFT + 2);
		cout << "分数：";
		unit::gotoxy(m_coor.X / 2+10, KLEFT + 2);
		cout << "目前关卡：";
	unit::gotoxy(m_coor.X / 2, m_coor.Y / 2);
}
void jiemian::begin()
{
	system("color 0f");
	char a;
	unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5);
	cout << "1.开始游戏";
	unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5 + 5);
	cout << "2.退出游戏";
	a = _getch();
	switch (a) {
	case '1':
		system("cls");
		break;

	case '2':
		system("cls");
		unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5);
		cout << "欢迎下次再来！";
		Sleep(3000);
		exit(0);
		break;
	default:
		system("cls");
		unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5);
		cout << "输入错误，请重新输入！" << endl;
		Sleep(2000);
		system("cls");
		begin();
	}
	system("color 4f");
}