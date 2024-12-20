using namespace std;
#include <iostream>
#include <windows.h>
#include "PlayerGame.h"
#include "FootGame.h"
#include "Mab.h"
#include "Enemy.h"

Mab mainMab(20, 40);
Foot foot[] = { Foot(mainMab), Foot(mainMab), Foot(mainMab), Foot(mainMab), Foot(mainMab), Foot(mainMab), Foot(mainMab) };
Player player(20, 10);
Enemy enemy(1, 1);

bool print = false;
void drawMab()
{
	system("cls");
	for (int i = 0; i < mainMab.getHeight(); ++i)
	{
		for (int j = 0; j < mainMab.getWidth(); ++j)
		{
			if (i == 0 || i == mainMab.getHeight() - 1)
				cout << "-";
			else if (j == 0 || j == mainMab.getWidth() - 1)
				cout << "|";
			else if (i == player.Y && j == player.X)
				cout << "O";
			else if (i == enemy.Y && j == enemy.X)
				cout << "X";
			else
			{
				print = false;
				for (int k = 0; k < size(foot); ++k)
				{
					if (i == foot[k].getY() && j == foot[k].getX())
					{
						cout << "*";
						print = true;
						break;
					}
				}
				if (print == false)	cout << " ";
			}
		}
		cout << endl;
	}
	cout << "score is " << player.score;
}

void input()
{
	if (GetKeyState(VK_UP) & 0x8000)
		player.dir = UP;
	else if (GetKeyState(VK_DOWN) & 0x8000)
		player.dir = DOWN;
	else if (GetKeyState(VK_LEFT) & 0x8000)
		player.dir = LEFT;
	else if (GetKeyState(VK_RIGHT) & 0x8000)
		player.dir = RIGHT;
}

void update()
{
	while (player.isDead == false)
	{
		input();
		player.Move(mainMab);
		enemy.move(player);
		if (player.X == enemy.X && player.Y == enemy.Y)
		{
			player.isDead = true;
			break;
		}
		for (int i = 0; i < size(foot); ++i)
		{
			if (player.X == foot[i].getX() && player.Y == foot[i].getY())
			{
				player.score++;
				foot[i].updatePos(mainMab);
			}
		}
		drawMab();
		Sleep(50);
	}
}

int main()
{
	update();
	return 0;
}