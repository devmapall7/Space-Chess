//Name:Lyubomir Kostov
//Project: Space Chess
//Date: 11/29/2018

#include "Bishop.h"

// Bishop movement; moveDirection works as follows:
// moveDirection = 1 means bishop is going up-right (y increases, x increases)
// moveDirection = 2 means bishop is going down-right (y decreases, x increases)
// moveDirection = 3 means bishop is going downw-left (y decreases, x decreases)
// moveDirection = 4 means bishop is going up-left (y increases, x decreases)
void Bishop::move(int moveDirection, double distance)
{
	if (moveDirection == 1)
	{
		this->y += distance;
		this->x += distance;
	}
	else if (moveDirection == 2)
	{
		this->y -= distance;
		this->x += distance;
	}
	else if (moveDirection == 3)
	{
		this->y -= distance;
		this->x -= distance;
	}
	else if (moveDirection == 4)
	{
		this->y += distance;
		this->x -= distance;
	}
	else cout << "Invalid move command!" << endl;
}