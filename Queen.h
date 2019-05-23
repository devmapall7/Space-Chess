#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	using Piece::Piece;
	virtual void move(int moveDirection, double distance);
};

