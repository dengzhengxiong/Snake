#include"show.h"
#include<iostream>
#include"unit.h"
#include<windows.h>
#include"snake.h"
jiemian::jiemian()
{
		HANDLE hOut;
		CONSOLE_SCREEN_BUFFER_INFO scr;

		hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* ��ȡ��׼������ */
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
		cout << "��";
	}
	for (int j=KUP;j<= m_coor.Y;j++)
	{
		unit::gotoxy(KUP, j);
		cout << "��";
	}
	for (int i = KLEFT; i <= m_coor.X -3; i++)
	{
		unit::gotoxy(i, m_coor.Y);
		cout << "��";
	}
	for (int j = KUP; j <= m_coor.Y; j++)
	{
		unit::gotoxy(m_coor.X -3,j);
		cout << "��";
	}
	for (int i = KLEFT; i <= m_coor.X - 3; i++)
	{
		unit::gotoxy(i, KLEFT+4);
		cout << "��";
	}
		unit::gotoxy(KLEFT+1, KLEFT + 2);
		cout << "��Ϸ���ƣ�̰����   ";
			cout << "���ߣ�������   ";
		unit::gotoxy(m_coor.X/2, KLEFT + 2);
		cout << "������";
		unit::gotoxy(m_coor.X / 2+10, KLEFT + 2);
		cout << "Ŀǰ�ؿ���";
	unit::gotoxy(m_coor.X / 2, m_coor.Y / 2);
}
void jiemian::begin()
{
	system("color 0f");
	char a;
	unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5);
	cout << "1.��ʼ��Ϸ";
	unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5 + 5);
	cout << "2.�˳���Ϸ";
	a = _getch();
	switch (a) {
	case '1':
		system("cls");
		break;

	case '2':
		system("cls");
		unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5);
		cout << "��ӭ�´�������";
		Sleep(3000);
		exit(0);
		break;
	default:
		system("cls");
		unit::gotoxy(m_coor.X / 2 - 5, m_coor.Y / 2 - 5);
		cout << "����������������룡" << endl;
		Sleep(2000);
		system("cls");
		begin();
	}
	system("color 4f");
}