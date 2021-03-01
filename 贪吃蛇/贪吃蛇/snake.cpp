#include"unit.h"
#include"snake.h"
#include<vector>
#include"food.h"
#include<conio.h>
#include"show.h"
#include<windows.h>
COORD m_coor;
int m=0;
snake::snake(int x, int y, int len, int grade,int level,int speed, Dir dir, char pic)
{
	headex = x;
	headey = y;
	m_len = len;
	m_grade = grade;
	m_level = level;
	m_speed = speed;
	m_dir = dir;
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coor.X = scr.srWindow.Right;
	m_coor.Y = scr.srWindow.Bottom;
	coor.X = m_coor.X;
	coor.Y = m_coor.Y;
	for (int i = 0; i < len; i++)
	{
		unit myunit(0, 0, pic);
		body.push_back(myunit);
		switch (m_dir)
		{
		case kup:
				body[i].m_x = headex;
				body[i].m_y = headey - i;
				break;
		case kdown:
					body[i].m_x = headex;
					body[i].m_y = headey + i;
					break;
		case kleft:
						body[i].m_x = headex + i;
						body[i].m_y = headey;
						break;
		case kright:
							body[i].m_x = headex - i;
							body[i].m_y = headey;
							break;
		default:
							break;
		}
	}
}
snake::~snake()
{
	
}
void snake::showsnake()
{
	for (int i = 0; i < m_len; i++)
	{
		body[i].show();
	}
}
void snake::erasesnake()
{

	for (int i = 0; i < m_len; i++)
	{
		body[i].erase();
	}
}
bool snake::eatFood(food *pFood)
{
	if (body[0].m_x == pFood->m_x && body[0].m_y == pFood->m_y)
	{
		m_grade = m_grade + 10;
		if (m_grade%30==0)
		{
			m_level = m_level + 1;
		}
		return true;
	}
	return false;
}
void snake::move()
{
	


		for (int i = m_len - 1; i > 0; i--)
		{
			body[i].m_x = body[i - 1].m_x;
			body[i].m_y = body[i - 1].m_y;
		}
		switch (m_dir)
		{
		case kup:
			body[0].m_y--;
			break;
		case kdown:
			body[0].m_y++;
			break;
		case kleft:
			body[0].m_x--;
			break;
		case kright:
			body[0].m_x++;
			break;
		default:
			break;

		}
		showsnake();
		Sleep(m_speed);
		erasesnake();
		changedir();
		coutgrade();
		coutlevel();
}
void snake::changedir()
{
	char ch = ' ';
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case 'w':
		case 'W':
			if (m_dir != kdown)
			{
				m_dir = kup;
			}
			break;
		case 's':
		case 'S':
			if (m_dir != kup)
			{
				m_dir = kdown;
			}
			break;
		case 'a':
		case 'A':
			if (m_dir != kright)
			{
				m_dir = kleft;
			}
			break;
		case 'd':
		case 'D':
			if (m_dir != kleft)
			{
				m_dir = kright;
			}
			break;
		case' ':
			m=MessageBox(NULL, TEXT("你暂停了游戏，是否继续？"), TEXT("你好"), MB_ICONINFORMATION | MB_YESNO);
			if (m == IDYES)//选择了“是”
			{
			}
			else
			{
				MessageBox(NULL, L"游戏结束", L" ", MB_YESNO | MB_ICONINFORMATION);
				system("cls");
				unit::gotoxy(coor.X / 2, coor.Y / 2);
				cout << "游戏结束";
			}
			break;
		default:
			break;
		}
	}
}
void snake::changesnake()
{
	char pic = '*';
	unit snakepoint(0,0,pic);
	body.push_back(snakepoint);
	m_len++;
	if (m_speed >= 50)
	{
		m_speed -= 10;
	}
}
bool snake::cheakwall()
{
	if (body[0].m_x == m_coor.X - 4 || body[0].m_x == jiemian::KLEFT + 1 || body[0].m_y == m_coor.Y || body[0].m_y == jiemian::KUP + 4)
	{
		/*int result=MessageBox(NULL, TEXT("啪！你的蛇撞墙了"), TEXT("你好"), MB_ICONINFORMATION | MB_YESNO);
		switch (result)
		{
		case IDYES:MessageBox(NULL, TEXT("您选择了YES"), TEXT("YES"), MB_OK); break;
		case IDNO:MessageBox(NULL, TEXT("您选择了NO"), TEXT("NO"), MB_OK); break;
		}*/
		return true;
	}
	else
		return false;
}
bool snake::cheakbody()
{
	for (int i = 1; i < m_len; i++)
	{
		if (body[0].m_x == body[i].m_x&&body[0].m_y == body[i].m_y)
		{
			return true;
		}
		else
			return false;
	}
}
void snake::coutgrade()
{
	unit::gotoxy(m_coor.X / 2+5, 2 + 2);
	cout << m_grade;
}
void snake::coutlevel()
{
	unit::gotoxy(m_coor.X / 2 + 20, 2 + 2);
	cout << m_level;
}