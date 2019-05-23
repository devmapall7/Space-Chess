//Name:Lyubomir Kostov
//Project: Space Chess
//Date: 11/29/2018

#include"Piece.h"
#include"Rook.h"
#include"Bishop.h"
#include "Queen.h"
#include<vector>
#include<typeinfo>
#include<time.h>
#include<algorithm>

// Constants for magic numbers
const double MAX_BOARD = 50.0;
const double SQUARE_SIDE = 2.0;
const double CIRLCE_RADIUS = 1.0;
const char* ROOK = "class Rook";
const char* QUEEN = "class Queen";
const char* BISHOP = "class Bishop";
// for all the collision functions I am assuming they are being used with the correct pieces in the parameters
// function doing circle collision with rectangle
bool CircleSquareCollision(const Piece& rook, const Piece& piece)
{
	// temporary variables to store positions for fewer function calls
	double cx, cy, rx, ry;

	cx = piece.getX();
	cy = piece.getY();
	rx = rook.getX();
	ry = rook.getY();

	// variables to store closest point
	double testX = cx, testY = cy;

	// checks for closest on x
	if (cx < rx - SQUARE_SIDE/2) testX = rx-SQUARE_SIDE/2; // left side
	else if (cx > rx + SQUARE_SIDE / 2) testX = rx + SQUARE_SIDE / 2; // right side
	// checks for closest on y
	if (cy < ry - SQUARE_SIDE / 2) testY = ry - SQUARE_SIDE/2; // bottom side
	else if (cy > ry + SQUARE_SIDE / 2) testY = ry + SQUARE_SIDE/2; // top side
	// variables to store distance from circle centre to closest point
	double distX = cx - testX;
	double distY = cy - testY;
	// calculating if the figures colide
	return (distX*distX + distY * distY) < (CIRLCE_RADIUS*CIRLCE_RADIUS);
}
// function doing circle collision with another circle
bool CircleCircleCollision(const Piece& piece1, const Piece& piece2)
{
	double x, y;
	x = piece1.getX()-piece2.getX();;
	y = piece1.getY()- piece2.getY();
	return x * x + y * y < (CIRLCE_RADIUS + CIRLCE_RADIUS)*(CIRLCE_RADIUS + CIRLCE_RADIUS);
}
// function doing square collision with another square
bool SquareSquareCollision(const Piece& rook1, const Piece& rook2)
{
	return (abs(rook1.getX() - rook2.getX()) < SQUARE_SIDE && abs(rook1.getY() - rook2.getY()) < SQUARE_SIDE);
}
// function to check if a specific piece collides with any other (done every time after movement)

bool Collision(const Piece& piece1, const Piece& piece2)
{
	if (&piece1 == &piece2) return 0;
	if (strcmp(typeid(piece1).name(), ROOK) == 0)
	{
		if (strcmp(typeid(piece2).name(), ROOK) == 0) return SquareSquareCollision(piece1, piece2);
		else return CircleSquareCollision(piece1, piece2);
	}
	else
	{
		if (strcmp(typeid(piece2).name(), ROOK) == 0) return CircleSquareCollision(piece2, piece1);
		else return CircleCircleCollision(piece1, piece2);
	}
}

bool double_equals(double a, double b, double epsilon = 0.001)
{
	return std::abs(a - b) < epsilon;
}

int main()
{
	int QueenCap = 0, RookCap = 0, BishopCap = 0;
	srand(static_cast <unsigned> (time(0)));
	// generating some pieces to move on the board
	vector<Piece*> pieces;
	pieces.push_back(new Queen(0.0, 0.0));
	pieces.push_back(new Rook(2.0, 0.0));
	pieces.push_back(new Bishop(-2.0, 0.0));
	pieces.push_back(new Queen(0.0, 2.0));
	pieces.push_back(new Rook(0.0, -2.0));
	pieces.push_back(new Bishop(2.0, 2.0));
	pieces.push_back(new Queen(-2.0, -2.0));
	pieces.push_back(new Rook(4.0, 0.0));
	pieces.push_back(new Bishop(-4.0, 0.0));
	pieces.push_back(new Queen(0.0, 4.0));
	pieces.push_back(new Rook(0.0, -4.0));
	pieces.push_back(new Bishop(4.0, 4.0));
	pieces.push_back(new Queen(-4.0, -4.0));
	pieces.push_back(new Rook(-2.0, 2.0));
	pieces.push_back(new Bishop(2.0, -2.0));
	pieces.push_back(new Queen(4.0, -4.0));
	pieces.push_back(new Rook(-4.0, 4.0));
	pieces.push_back(new Bishop(7.0, 7.0));
	for (int j = 0; j < 1000; j++)
	{
		
		{for (int i = 0; i < pieces.size(); i++)
			// Queen movement randomization
			if (strcmp(typeid(*pieces[i]).name(), QUEEN) == 0)
			{
				int moveDirection = rand() % 8 + 1;
				double distance=0;
				switch(moveDirection)
				{
				case 1: 
				{
					if (double_equals(MAX_BOARD - pieces[i]->getY(),0)) break;
					distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(MAX_BOARD - pieces[i]->getY())));
				}
				case 2:
				{
					if (double_equals(MAX_BOARD - max(pieces[i]->getY(),pieces[i]->getX()),0)) break;
					distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(MAX_BOARD - max(pieces[i]->getY(), pieces[i]->getX()))));
				}
				case 3:
				{
					if (double_equals(MAX_BOARD - pieces[i]->getX(),0)) break;
					distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(MAX_BOARD - pieces[i]->getX())));
				}
				case 4:
				{
					if (double_equals(MAX_BOARD + pieces[i]->getY(),0) || double_equals(MAX_BOARD - pieces[i]->getX(),0)) break;
					if (MAX_BOARD + pieces[i]->getY() < MAX_BOARD - pieces[i]->getX()) distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(MAX_BOARD + pieces[i]->getY())));
					else distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(MAX_BOARD - pieces[i]->getX())));
				}
				case 5:
				{
					if (double_equals(MAX_BOARD + pieces[i]->getY(),0)) break;
					distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(MAX_BOARD + pieces[i]->getY())));
				}
				case 6:
				{
					if (double_equals(MAX_BOARD + min(pieces[i]->getY(), pieces[i]->getX()),0)) break;
					distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(MAX_BOARD + min(pieces[i]->getY(), pieces[i]->getX()))));
				}
				case 7:
				{
					if (double_equals(MAX_BOARD + pieces[i]->getX(),0)) break;
					distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(MAX_BOARD + pieces[i]->getX())));
				}
				case 8:
				{
					if (double_equals(MAX_BOARD - pieces[i]->getY(),0) || (double_equals(MAX_BOARD + pieces[i]->getX(),0))) break;
					if (MAX_BOARD - pieces[i]->getY() < MAX_BOARD + pieces[i]->getX()) distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(MAX_BOARD - pieces[i]->getY())));
					else distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(MAX_BOARD + pieces[i]->getX())));
				}
				}
				if (pieces[i]->getX() + distance<MAX_BOARD && pieces[i]->getX() - distance > -MAX_BOARD && pieces[i]->getY() + distance < MAX_BOARD && pieces[i]->getY() - distance > -MAX_BOARD) pieces[i]->move(moveDirection, distance);
				for (int k = 0,  t=0; k < pieces.size(); k++, t++)
				{
					if (Collision(*pieces[i], *pieces[k]))
					{
						pieces.erase(pieces.begin() + k);
						if (k < i) i--;
						k--;
						QueenCap++;
					}
				}
			}
		// Bishop and rook movement randomization
			else
			{
				int moveDirection = rand() % 4 + 1;
				double distance = 0;
				//Rook movement randomization
				if (strcmp(typeid(*pieces[i]).name(), ROOK) == 0)
				{
					switch (moveDirection)
					{
					case 1:
					{
						if (double_equals(MAX_BOARD - pieces[i]->getY(), 0)) break;
						distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_BOARD - pieces[i]->getY())));
					}
					case 2:
					{
						if (double_equals(MAX_BOARD - pieces[i]->getX(), 0)) break;
						distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_BOARD - pieces[i]->getX())));
					}
					case 3:
					{
						if (double_equals(MAX_BOARD + pieces[i]->getY(), 0)) break;
						distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_BOARD + pieces[i]->getY())));
					}
					case 4:
					{
						if (double_equals(MAX_BOARD + pieces[i]->getX(), 0)) break;
						distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_BOARD + pieces[i]->getX())));
					}

					}
					if (pieces[i]->getX()+distance<MAX_BOARD && pieces[i]->getX() - distance > -MAX_BOARD && pieces[i]->getY() + distance < MAX_BOARD && pieces[i]->getY() - distance > -MAX_BOARD) pieces[i]->move(moveDirection, distance);
					for (int k = 0, t=0; k < pieces.size(); k++,t++)
					{
						if (Collision(*pieces[i], *pieces[k]))
						{
							pieces.erase(pieces.begin() + k);
							if (k < i) i--;
							k--;
							RookCap++;
						}
					}
				}
				//Bishop movement randomization
				else
				{
					switch (moveDirection)
					{
					case 1:
					{
						if (double_equals(MAX_BOARD - max(pieces[i]->getY(), pieces[i]->getX()), 0)) break;
						distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_BOARD - max(pieces[i]->getY(), pieces[i]->getX()))));
					}
					case 2:
					{
						if (double_equals(MAX_BOARD + pieces[i]->getY(), 0) || double_equals(MAX_BOARD - pieces[i]->getX(), 0)) break;
						if (MAX_BOARD + pieces[i]->getY() < MAX_BOARD - pieces[i]->getX()) distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_BOARD + pieces[i]->getY())));
						else distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_BOARD - pieces[i]->getX())));
					}
					case 3:
					{
						if (double_equals(MAX_BOARD + min(pieces[i]->getY(), pieces[i]->getX()), 0)) break;
						distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_BOARD + min(pieces[i]->getY(), pieces[i]->getX()))));
					}
					case 4:
					{
						if (double_equals(MAX_BOARD - pieces[i]->getY(), 0) || (double_equals(MAX_BOARD + pieces[i]->getX(), 0))) break;
						if (MAX_BOARD - pieces[i]->getY() < MAX_BOARD + pieces[i]->getX()) distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_BOARD - pieces[i]->getY())));
						else distance = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_BOARD + pieces[i]->getX())));
					}

					}
					if (pieces[i]->getX() + distance<MAX_BOARD && pieces[i]->getX() - distance > -MAX_BOARD && pieces[i]->getY() + distance < MAX_BOARD && pieces[i]->getY() - distance > -MAX_BOARD) pieces[i]->move(moveDirection, distance);
					for (int k = 0, t=0; k < pieces.size(); k++,t++)
					{
						if (Collision(*pieces[i], *pieces[k]))
						{
							pieces.erase(pieces.begin() + k);
							if (k < i) i--;
							k--;
							BishopCap++;
						}
					}
				}
			}
		}
		if (pieces.size() < 3) break;
	}
	cout << QueenCap << ' ' << BishopCap << ' ' << RookCap << endl;
	system("PAUSE");
	return 0;
}