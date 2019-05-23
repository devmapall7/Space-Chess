//Name:Lyubomir Kostov
//Project: Space Chess
//Date: 11/29/2018

#include<iostream>
using namespace std;

#pragma once
class Piece
{
protected:
	// x- row position on board of piece centre
	// y- column position on board of piece centre
	double x,y;
public:
	Piece();
	Piece(double x, double y);
	// move method takes 2 variables, 
	// moveDirection is 0-3 for bishops and rooks and 0-7 for queens
	// distance is the distance it needs to travel( increment both x and y with certain value for diagonal movement or only one for horizontal/vertical)
	virtual void move(int moveDirection, double distance) = 0;
	// getter methods
	double getX() const;
	double getY() const;
	~Piece();
};

