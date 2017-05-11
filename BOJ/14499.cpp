#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dice[6] = { 0,0,0,0,0,0 };
int map[20][20];
int nextstep[4][2] = { { 0,1 },{ 0,-1 },{ -1,0 },{ 1,0 } };

void roll(int direction)
{
	int temp = dice[0];
	if (direction == 1)
	{
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
	}
	else if (direction == 2)
	{
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
	}
	else if (direction == 3)
	{
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}
	else if (direction == 4)
	{
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
	}
}
int main()
{
	int x, y, N, M, K;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for (int z = 0; z < K; z++)
	{//1µ¿ 2¼­ 3ºÏ 4³²
		int direction;
		scanf("%d", &direction);
		x += nextstep[direction-1][0];
		y += nextstep[direction-1][1];
		if (x < 0)
		{
			x = 0;
		}
		else if (x >= N)
		{
			x = N - 1;
		}
		else if (y < 0)
		{
			y = 0;
		}
		else if (y >= M)
		{
			y = M - 1;
		}
		else
		{
			roll(direction);
			if (map[x][y] == 0)
			{
				map[x][y] = dice[5];
			}
			else
			{
				dice[5] = map[x][y];
				map[x][y] = 0;
			}
			printf("%d\n", dice[0]);
		}
	}
	return 0;
}