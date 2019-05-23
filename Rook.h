//Name:Lyubomir Kostov
//Project: Space Chess
//Date: 11/29/2018

#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
public:
	using Piece::Piece;
	virtual void move(int moveDirection, double distance);
};

