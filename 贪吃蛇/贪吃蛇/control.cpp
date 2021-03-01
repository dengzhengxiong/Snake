#include"control.h"
#include"unit.h"
#include<windows.h>
//COORD m_coor;
control::control()
{
	this->jiemianpoint = new jiemian();
	this->snakepoint = new snake();
	this->foodpoint = new food();
	//HANDLE hOut;
	//CONSOLE_SCREEN_BUFFER_INFO scr;

	//hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	//GetConsoleScreenBufferInfo(hOut, &scr);
	//m_coor.X = scr.srWindow.Right;
	//m_coor.Y = scr.srWindow.Bottom;
}
control::~control()
{
	delete jiemianpoint, snakepoint, foodpoint;
	jiemianpoint = NULL;
	snakepoint = NULL;
	foodpoint = NULL;
}
void control::foodjudge()
{
	for (int i = 0; i < snakepoint->m_len; i++)
	{
		if (foodpoint->m_x == snakepoint->body[i].m_x&&foodpoint->m_y == snakepoint->body[i].m_y)
		{
			foodpoint->CreatPos();
			foodpoint->show();
		}
	}
}
void control::init()
{
	jiemianpoint->begin();
	jiemianpoint->initi();
	foodpoint->CreatPos();
	foodpoint->show();
	snakepoint->showsnake();
	int key = _getch();
	if (key) {
		while (1) {

			foodjudge();
			snakepoint->erasesnake();
			snakepoint->move();
			if (snakepoint->cheakbody()||snakepoint->cheakwall())
			{
				int m = MessageBox(NULL, L"游戏结束，是否重新开始？", L" ", MB_YESNO | MB_ICONINFORMATION);
				if (m == IDYES)//选择了“是”
				{
					system("cls");
					control* temp = new control();
					temp->init();

				}
				else
				{
					MessageBox(NULL, L"游戏结束", L" ", MB_YESNO | MB_ICONINFORMATION);
					system("cls");
					unit::gotoxy(snakepoint->coor.X / 2,snakepoint->coor.Y / 2);
					cout << "游戏结束";
				}

			}
			if (snakepoint->eatFood(foodpoint)) {
				snakepoint->changesnake();
				foodpoint->CreatPos();
				foodpoint->show();
			}
		}




	}
}