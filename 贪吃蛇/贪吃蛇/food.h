#pragma once
#include "unit.h"
#include <cstdlib>
#include <ctime>
#include<windows.h>
class food :
	public unit
{
public:
	COORD m_coor;
public:
	food();
	~food();
	void CreatPos();
};