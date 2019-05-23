//Name:Lyubomir Kostov
//Project: Space Chess
//Date: 11/29/2018

#include "Queen.h"


void Queen::move(int moveDirection, double distance)
{
	if (moveDirection == 1)
	{
		this->y += distance;
	}
	else if (moveDirection == 2)
	{
		this->y += distance;
		this->x += distance;
	}
	else if (moveDirection == 3)
	{
		this->x += distance;
	}
	else if (moveDirection == 4)
	{
		this->y -= distance;
		this->x += distance;
	}
	else if (moveDirection == 5)
	{
		this->y -= distance;
	}
	else if (moveDirection == 6)
	{
		this->y -= distance;
		this->x -= distance;
	}
	else if (moveDirection == 7)
	{
		this->x -= distance;
	}
	else if (moveDirection == 8)
	{
		this->y += distance;
		this->x -= distance;
	}
	else cout << "Invalid move command!" << endl;
}
