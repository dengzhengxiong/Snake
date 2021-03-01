#pragma once
#include<windows.h>
class jiemian
{
public:
	const static int KLEFT = 2;
	const static int KUP = 2;
	const static int KWIDTH = 120;
	const static int KHEIGHT = 30;
	COORD m_coor;
public:
	jiemian();
	~jiemian();
	void initi();
	void begin();
	/*void cheakwall();
	void cheakdie();*/
};
