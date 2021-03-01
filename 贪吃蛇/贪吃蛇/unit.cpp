#include "unit.h"
unit::unit(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_chr = pic;
}


unit::~unit()
{
}

void unit::show()
{
	gotoxy(m_x, m_y);
	cout << m_chr;
}

void unit::erase()
{
	gotoxy(m_x, m_y);
	cout << " ";
}

void unit::gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(screen, position);
}