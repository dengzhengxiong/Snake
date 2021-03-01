#pragma once
#include"snake.h"
#include"food.h"
#include"show.h"
class control
{
public:
	jiemian *jiemianpoint;
	snake *snakepoint;
	food *foodpoint;
public:
	control();
	virtual ~control();
	void init();
	void foodjudge();
};
