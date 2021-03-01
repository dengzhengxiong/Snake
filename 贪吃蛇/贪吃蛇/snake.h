#pragma once
#include"unit.h"
#include<vector>
#include"food.h"
#include<conio.h>
static food MyFood;
typedef enum Dir
{
	kup, kdown, kleft, kright
};
class snake
{
public:
	int headex;
	int headey;
	int m_speed;
	int m_len;
	int m_grade;
	int m_level;
	COORD coor;
	Dir m_dir;
	vector<unit>body;
	snake(int x = 40, int y = 10, int len = 4, int grade = 0,int m_level = 0, int speed = 200, Dir dir = kright, char pic = '*');
	~snake();
	void showsnake();
	void erasesnake();
	bool eatFood(food *pFood);
	void move();
	void changedir();
	void changesnake();
	bool cheakwall();
	bool cheakbody();
	void coutgrade();
	void coutlevel();
};