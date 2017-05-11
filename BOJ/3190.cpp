#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> body;
queue<pair<int, char>> orders;

int main()
{
	int N;
	cin >> N;
	int map[102][102];
	memset(map, 0, sizeof(map));
	int apples;
	cin >> apples;
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
				map[i][j] = 1000;
		}
	}
	for (int i = 0; i < apples; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}
	int order;
	cin >> order;

	for (int z = 0; z < order; z++)
	{
		int temp1;
		char temp2;
		cin >> temp1 >> temp2;
		orders.push({ temp1,temp2 });
	}
	int result = 1;
	bool die = true;
	int x, y;
	x = y = 1;
	body.push_back({ x, y });
	int nextstep[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	//µ¿ ³² ¼­ ºÏ
	int direction = 0;
	int time = 0;
	char face = 0;
	while (die)
	{
		if (time < result && !orders.empty())
		{
			if (face == 'L')
			{
				direction = (3 + direction) % 4;
				face = 0;
			}
			else if (face == 'D')
			{
				direction = (1 + direction) % 4;
				face = 0;
			}
			time = orders.front().first;
			face = orders.front().second;
			orders.pop();
		}
		else if(time < result && orders.empty())
		{
			if (face == 'L')
			{
				direction = (3 + direction) % 4;
				face = 0;
			}
			else if (face == 'D')
			{
				direction = (1 + direction) % 4;
				face = 0;
			}
			time = 99999;
		}
		x += nextstep[direction][0];
		y += nextstep[direction][1];
		if (map[x][y] == 1000)
		{
			die = false;
			break;
		}
		
		for (auto check : body)
		{
			if (check.first == x && check.second == y)
			{
				die = false;
				break;
			}
		}
		if (!die)
			continue;
		if (map[x][y] != 1)
		{
			body.erase(body.begin());
		}
		else
		{
			map[x][y] = 0;
		}
		body.push_back({ x,y });
		result++;
	}
	cout << result;
	return 0;
}