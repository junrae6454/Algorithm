#include <iostream>
#include <string>
using namespace std;
int x, y;
int gx, gy;
int result = -1;
int asdf = 0;
int go(string maptemp[], int rx, int ry, int bx, int by, int count, int direction)
{
	cout << asdf++ << endl;
	string map[10];
	for (int i = 0; i < x; i++)
	{
		map[i] = maptemp[i];
	}
	if (result != -1 && count > result)
	{
		return 0;
	}
	if (count > 9)
	{
		return -1;
	}
	else
	{//direction 1 µ¿ 2 ¼­ 3 ³² 4 ºÏ
		if (direction == 1)
		{
			if (ry > by)
			{
				int tempy = ry;
				while (map[rx][tempy] != '#' && map[rx][tempy] != 'O')
				{
					tempy++;
				}
				if (map[rx][tempy] != 'O')
				{
					map[rx][ry] = '.';
					map[rx][tempy - 1] = 'R';
					ry = tempy - 1;
				}
				else
				{
					map[rx][ry] = '.';
					ry = tempy;
				}

				tempy = by;
				while (map[bx][tempy] != '#' && map[bx][tempy] != 'O' && map[bx][tempy] != 'R')
				{
					tempy++;
				}
				if (map[bx][tempy] != 'O')
				{
					map[bx][by] = '.';
					map[bx][tempy - 1] = 'B';
					by = tempy - 1;
				}
				else
				{
					map[bx][by] = '.';
					by = tempy;
				}
			}
			else
			{
				int tempy = by;
				while (map[bx][tempy] != '#' && map[bx][tempy] != 'O')
				{
					tempy++;
				}
				if (map[bx][tempy] != 'O')
				{
					map[bx][by] = '.';
					map[bx][tempy - 1] = 'B';
					by = tempy - 1;
				}
				else
				{
					map[bx][by] = '.';
					by = tempy;
				}
				tempy = ry;
				while (map[rx][tempy] != '#' && map[rx][tempy] != 'O' && map[rx][tempy] != 'B')
				{
					tempy++;
				}
				if (map[rx][tempy] != 'O')
				{
					map[rx][ry] = '.';
					map[rx][tempy - 1] = 'R';
					ry = tempy - 1;
				}
				else
				{
					map[rx][ry] = '.';
					ry = tempy;
				}
			}
		}
		else if (direction == 2)
		{
			if (ry < by)
			{
				int tempy = ry;
				while (map[rx][tempy] != '#' && map[rx][tempy] != 'O')
				{
					tempy--;
				}
				if (map[rx][tempy] != 'O')
				{
					map[rx][ry] = '.';
					map[rx][tempy + 1] = 'R';
					ry = tempy + 1;
				}
				else
				{
					map[rx][ry] = '.';
					ry = tempy;
				}
				tempy = by;
				while (map[bx][tempy] != '#' && map[bx][tempy] != 'O' && map[bx][tempy] != 'R')
				{
					tempy--;
				}
				if (map[bx][tempy] != 'O')
				{
					map[bx][by] = '.';
					map[bx][tempy + 1] = 'B';
					by = tempy + 1;
				}
				else
				{
					map[bx][by] = '.';
					by = tempy;
				}
			}
			else
			{
				int tempy = by;
				while (map[bx][tempy] != '#' && map[bx][tempy] != 'O')
				{
					tempy--;
				}
				if (map[bx][tempy] != 'O')
				{
					map[bx][by] = '.';
					map[bx][tempy + 1] = 'B';
					by = tempy + 1;
				}
				else
				{
					map[bx][by] = '.';
					by = tempy;
				}
				tempy = ry;
				while (map[rx][tempy] != '#' && map[rx][tempy] != 'O' && map[rx][tempy] != 'B')
				{
					tempy--;
				}
				if (map[rx][tempy] != 'O')
				{
					map[rx][ry] = '.';
					map[rx][tempy + 1] = 'R';
					ry = tempy + 1;
				}
				else
				{
					map[rx][ry] = '.';
					ry = tempy;
				}
			}
		}
		else if (direction == 3)
		{
			if (rx > bx)
			{
				int tempx = rx;
				while (map[tempx][ry] != '#' && map[tempx][ry] != 'O')
				{
					tempx++;
				}
				if (map[tempx][ry] != 'O')
				{
					map[rx][ry] = '.';
					map[tempx - 1][ry] = 'R';
					rx = tempx - 1;
				}
				else
				{
					map[rx][ry] = '.';
					rx = tempx;
				}
				tempx = bx;
				while (map[tempx][by] != '#' && map[tempx][by] != 'O' && map[tempx][by] != 'R')
				{
					tempx++;
				}
				if (map[tempx][by] != 'O')
				{
					map[bx][by] = '.';
					map[tempx - 1][by] = 'B';
					bx = tempx - 1;
				}
				else
				{
					map[bx][by] = '.';
					bx = tempx;
				}
			}
			else
			{
				int tempx = bx;
				while (map[tempx][by] != '#' && map[tempx][by] != 'O')
				{
					tempx++;
				}
				if (map[tempx][by] != 'O')
				{
					map[bx][by] = '.';
					map[tempx - 1][by] = 'B';
					bx = tempx - 1;
				}
				else
				{
					map[bx][by] = '.';
					bx = tempx;
				}
				tempx = rx;
				while (map[tempx][ry] != '#' && map[tempx][ry] != 'O' && map[tempx][ry] != 'B')
				{
					tempx++;
				}
				if (map[tempx][ry] != 'O')
				{
					map[rx][ry] = '.';
					map[tempx - 1][ry] = 'R';
					rx = tempx - 1;
				}
				else
				{
					map[rx][ry] = '.';
					rx = tempx;
				}
			}
		}
		else if (direction == 4)
		{
			if (rx < bx)
			{
				int tempx = rx;
				while (map[tempx][ry] != '#' && map[tempx][ry] != 'O')
				{
					tempx--;
				}
				if (map[tempx][ry] != 'O')
				{
					map[rx][ry] = '.';
					map[tempx + 1][ry] = 'R';
					rx = tempx + 1;
				}
				else
				{
					map[rx][ry] = '.';
					rx = tempx;
				}
				tempx = bx;
				while (map[tempx][by] != '#' && map[tempx][by] != 'O' && map[tempx][by] != 'R')
				{
					tempx--;
				}
				if (map[tempx][by] != 'O')
				{
					map[bx][by] = '.';
					map[tempx + 1][by] = 'B';
					bx = tempx + 1;
				}
				else
				{
					map[bx][by] = '.';
					bx = tempx;
				}
			}
			else
			{
				int tempx = bx;
				while (map[tempx][by] != '#' && map[tempx][by] != 'O')
				{
					tempx--;
				}
				if (map[tempx][by] != 'O')
				{
					map[bx][by] = '.';
					map[tempx + 1][by] = 'B';
					bx = tempx + 1;
				}
				else
				{
					map[bx][by] = '.';
					bx = tempx;
				}
				tempx = rx;
				while (map[tempx][ry] != '#' && map[tempx][ry] != 'O' && map[tempx][ry] != 'B')
				{
					tempx--;
				}
				if (map[tempx][ry] != 'O')
				{
					map[rx][ry] = '.';
					map[tempx + 1][ry] = 'R';
					rx = tempx + 1;
				}
				else
				{
					map[rx][ry] = '.';
					rx = tempx;
				}
			}
		}
	}

	if (bx == gx && by == gy)
	{
		return -1;
	}
	else if (rx == gx && ry == gy)
	{
		if (count < 10 && result == -1)
		{
			result = count + 1;
		}
		else if (result > count + 1)
		{
			result = count + 1;
		}
		return 0;
	}

	if (map[rx][ry + 1] != '#' || map[bx][by + 1] != '#')
		go(map, rx, ry, bx, by, count + 1, 1);
	if (map[rx][ry - 1] != '#' || map[bx][by - 1] != '#')
		go(map, rx, ry, bx, by, count + 1, 2);
	if (map[rx + 1][ry] != '#' || map[bx + 1][by] != '#')
		go(map, rx, ry, bx, by, count + 1, 3);
	if (map[rx - 1][ry] != '#' || map[bx - 1][by] != '#')
		go(map, rx, ry, bx, by, count + 1, 4);
	return -1;
}

int main()
{
	cin >> x >> y;
	string map[10];
	int rx, ry, bx, by;
	for (int i = 0; i < x; i++)
	{
		cin >> map[i];
		for (int j = 0; j < y; j++)
		{
			if (map[i][j] == 'R')
			{
				rx = i;
				ry = j;
			}
			if (map[i][j] == 'B')
			{
				bx = i;
				by = j;
			}
			if (map[i][j] == 'O')
			{
				gx = i;
				gy = j;
			}
		}
	}

	go(map, rx, ry, bx, by, 0, 1);//µ¿
	go(map, rx, ry, bx, by, 0, 2);//¼­
	go(map, rx, ry, bx, by, 0, 3);//³²
	go(map, rx, ry, bx, by, 0, 4);//ºÏ

	cout << result;
	return 0;
}