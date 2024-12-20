#pragma once

class Mab
{
	int width, height;
public:
	Mab(int h, int w )
	{
		height = h;
		width = w;
	}
	int getWidth() { return width; }
	int getHeight()	{ return height; }
};