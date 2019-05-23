//Name:Lyubomir Kostov
//Project: Space Chess
//Date: 11/29/2018

#include "Rook.h"
// Rook movement; moveDirection works as follows:
// moveDirection = 1 means rook is going upwards (y increases)
// moveDirection = 2 means rook is going right (x increases)
// moveDirection = 3 means rook is going downwards (y decreases)
// moveDirection = 4 means rook is going left (x decreases)
void Rook::move(int moveDirection, double distance)
{
	if (moveDirection == 1)
	{
		this->y += distance;
	}
	else if (moveDirection == 2)
	{
		this->x += distance;
	}
	else if (moveDirection == 3)
	{
		this->y -= distance;
	}
	else if (moveDirection == 4)
	{
		this->x -= distance;
	}
	else cout << "Invalid move command!" << endl;
}