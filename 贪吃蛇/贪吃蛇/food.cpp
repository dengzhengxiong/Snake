#include "food.h"

food::food()
{
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coor.X = scr.srWindow.Right;
	m_coor.Y = scr.srWindow.Bottom;
}

food::~food()
{

}

void food::CreatPos()
{
	//todo;
	//m_x = randromNum();
	//m_y = randromNum();
	srand((int)time(0));
	m_x = KLEFT + 1 + rand() % (m_coor.X - 6);
	m_y = KUP + 5 + rand() % (m_coor.Y - 7);
}