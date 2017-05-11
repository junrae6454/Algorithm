#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int N, M;
int result = -1;
int dp[9][9];
string* rotate_maps(int x, int y, string* maps)
{
	for (int i = 1; i < M; i++)
	{//가로
		if (i == y)
		{
			continue;
		}
		else if (maps[x][i] == 'C')
		{
			maps[x][i] = 'D';
		}
		else if (maps[x][i] == 'D')
		{
			maps[x][i] = 'C';
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (i == x)
		{
			continue;
		}
		else if( maps[i][y] == 'C')
		{
			maps[i][y] = 'D';
		}
		else if (maps[i][y] == 'D')
		{
			maps[i][y] = 'C';
		}
	}
	return maps;
}
/*
A 네방향문
B 밀실
C 위아래
D 좌우
*/
int go(int x, int y, string maps[], int time)
{

	if (x == N && y == M)
	{
		if (result == -1 || result > time)
			result = time;
	}
	if (dp[x][y] < time && dp[x][y] != -1)
	{
		return 0;
	}
	else
	{
		dp[x][y] = time;
	}
	/*
	cout << "====== count : " << time << "============" << endl;
	for (int i = 1; i <= N; i++)
		cout << maps[i] << endl;
	cout << endl;
	*/
	if (maps[x][y] == 'A')
	{
		if (maps[x + 1][y] == 'A' || maps[x + 1][y] == 'C')
		{
			go(x + 1, y, maps, time + 1);
		}
		if (maps[x - 1][y] == 'A' || maps[x - 1][y] == 'C')
		{
			go(x - 1, y, maps, time + 1);
		}
		if (maps[x][y + 1] == 'A' || maps[x][y + 1] == 'D')
		{
			go(x, y + 1, maps, time + 1);
		}
		if (maps[x][y - 1] == 'A' || maps[x][y - 1] == 'D')
		{
			go(x, y - 1, maps, time + 1);
		}
	}
	else if (maps[x][y] == 'B')
	{
		return 0;
	}
	else if (maps[x][y] == 'C')
	{
		if (maps[x + 1][y] == 'A' || maps[x + 1][y] == 'C')
		{
			go(x + 1, y, maps, time + 1);
		}
		if (maps[x - 1][y] == 'A' || maps[x - 1][y] == 'C')
		{
			go(x - 1, y, maps, time + 1);
		}
	}
	else if (maps[x][y] == 'D')
	{
		if (maps[x][y + 1] == 'A' || maps[x][y + 1] == 'D')
		{
			go(x, y + 1, maps, time + 1);
		}
		if (maps[x][y - 1] == 'A' || maps[x][y - 1] == 'D')
		{
			go(x, y - 1, maps, time + 1);
		}
	}

	string mapstemp[9];
	for (int i = 0; i <= N+1; i++)
	{
		mapstemp[i] = maps[i];
	}
	rotate_maps(x, y, mapstemp);
	
	
	if (mapstemp[x][y] == 'A')
	{
		if (mapstemp[x + 1][y] == 'A' || mapstemp[x + 1][y] == 'C')
		{
			go(x + 1, y, mapstemp, time + 2);
		}
		if (mapstemp[x - 1][y] == 'A' || mapstemp[x - 1][y] == 'C')
		{
			go(x - 1, y, mapstemp, time + 2);
		}
		if (mapstemp[x][y + 1] == 'A' || mapstemp[x][y + 1] == 'D')
		{
			go(x, y + 1, mapstemp, time + 2);
		}
		if (mapstemp[x][y - 1] == 'A' || mapstemp[x][y - 1] == 'D')
		{
			go(x, y - 1, mapstemp, time + 2);
		}
	}
	else if (mapstemp[x][y] == 'B')
	{
		return 0;
	}
	else if (mapstemp[x][y] == 'C')
	{
		if (mapstemp[x + 1][y] == 'A' || mapstemp[x + 1][y] == 'C')
		{
			go(x + 1, y, mapstemp, time + 2);
		}
		if (mapstemp[x - 1][y] == 'A' || mapstemp[x - 1][y] == 'C')
		{
			go(x - 1, y, mapstemp, time + 2);
		}
	}
	else if (mapstemp[x][y] == 'D')
	{
		if (mapstemp[x][y + 1] == 'A' || mapstemp[x][y + 1] == 'D')
		{
			go(x, y + 1, mapstemp, time + 2);
		}
		if (mapstemp[x][y - 1] == 'A' || mapstemp[x][y - 1] == 'D')
		{
			go(x, y - 1, mapstemp, time + 2);
		}
	}
	return 0;
}
int main()
{
	string maps[9];
	cin >> N >> M;
	for (int i = 0; i <= N + 1; i++)
	{
		maps[i] = "BBBBBBBBB";
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> maps[i];
		maps[i] = "B" + maps[i] + "B";
	}
	memset(dp, -1, sizeof(dp));
	go(1, 1, maps, 0);
	cout << result << endl;
	return 0;
}