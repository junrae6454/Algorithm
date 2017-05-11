#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int map[50][50];
int find(int x, int y)
{
	int absx = abs(x);
	int absy = abs(y);
	int round = absx > absy ? absx : absy;
	int big = (2 * round + 1)*(2 * round + 1);
	int target = big;
	if (x == round )
	{//æ∆∑ß¡Ÿ
		target = big - (round - y);
	}
	else if (x == -round)
	{//¿≠¡Ÿ
		target = big - (4 * round) - (round + y);
	}
	else
	{
		if (y == round)
		{
			target = big - (6 * round) - (round + x);
		}
		else if (y == -round)
		{
			target = big - (2 * round) -(round - x);
		}
		else
		{
			cout << "æ¯¥¬ƒ…¿ÃΩ∫ : x : " << x << " y : " << y << endl;
		}
	}
	return target;
}
int main()
{
//	cout << mid_x;
//	cout << mid_y;
	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int max = 0;
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			map[i-r1][j-c1] = find(i, j);
			if (max < map[i - r1][j - c1])
				max = map[i - r1][j - c1];
		}
	}
	int digit=0;
	while ( max != 0)
	{
		max = max / 10;
		digit++;
	}
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			cout.width(digit);
			cout << map[i - r1][j - c1] << ' ';
		}
		cout << endl;
	}

	return 0;
}