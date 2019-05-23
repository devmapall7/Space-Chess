//Name:Lyubomir Kosto
//Project: Space Chess
//Date: 11/29/2018

#include "Piece.h"


Piece::Piece()
{
	x = 0;
	y = 0;
}

Piece::Piece(double x, double y) : x(x), y(y) {}

double Piece::getX() const
{
	return x;
}

double Piece::getY() const
{
	return y;
}

Piece::~Piece()
{
}
