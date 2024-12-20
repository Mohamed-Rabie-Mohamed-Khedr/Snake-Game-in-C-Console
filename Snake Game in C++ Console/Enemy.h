#pragma once
#include "PlayerGame.h"
class Enemy
{
	short step = 1;
public:
	int X;
	int Y;
	Enemy(int x, int y)
	{
		X = x;
		Y = y;
	}
	void move(Player player)
	{
		if (step == 1) step = 0;
		else
		{
			step++;
			if (player.X > X) X += 1;
			else if (player.X < X) X -= 1;
			if (player.Y > Y) Y += 1;
			else if (player.Y < Y) Y -= 1;
		}
	}
};