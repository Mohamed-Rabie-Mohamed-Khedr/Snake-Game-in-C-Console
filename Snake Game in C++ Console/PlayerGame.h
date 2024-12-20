#pragma once
#include "Mab.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class Player
{
public:
	int X, Y;
	Direction dir = Direction::UP;
	int score = 0;
	bool isDead = false;
		
	Player(int x, int y)
	{
		X = x;
		Y = y;
	}
	
	void Move(Mab m)
	{
		if (dir == UP && Y > 1)
		{
			Y -= 1;
		}
		else if (dir == DOWN && Y < m.getHeight() - 2)
		{
			Y += 1;
		}
		else if (dir == LEFT && X > 1)
		{
			X -= 1;
		}
		else if (dir == RIGHT && X < m.getWidth() - 2)
		{
			X += 1;
		}
	}
};