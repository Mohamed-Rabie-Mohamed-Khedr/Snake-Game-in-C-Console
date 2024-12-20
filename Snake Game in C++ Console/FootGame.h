#pragma once
using namespace std;
#include <random>
#include "Mab.h"

class Foot
{
	int xpos, ypos;
public:
	Foot(Mab m)
	{
		updatePos(m);
	}
	void updatePos(Mab m)
	{
		random_device rd;
		uniform_int_distribution<> dis(1, m.getWidth() - 2);
		xpos = dis(rd);
		uniform_int_distribution<> dis2(1, m.getHeight() - 2);
		ypos = dis2(rd);
	}
	int getX() { return xpos; }
	int getY() { return ypos; }
};