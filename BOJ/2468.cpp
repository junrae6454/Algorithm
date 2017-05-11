#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int maps[102][102];
int dp[102][102][102];
int check[102][102][102];

int main()
{
	int N;
	cin >> N;
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] > max)
				max = maps[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < max; k++)
			{
				if (maps[i][j] - k > 0)
					dp[k][i][j] = 1;
				else
					dp[k][i][j] = 0;
			}
		}
	}
	int max_result = 0;
	for (int k = 0; k < max; k++)
	{
		int result = 0;
		int i = 0, j = 0;
		for (i=1; i <= N; i++)
		{
			for (j=1; j <= N; j++)
			{
				if (dp[k][i][j] == 1 && check[k][i][j] == 0)
				{
					queue<pair<int, int>> a;
					a.push({ i,j });
					check[k][i][j] = 1;
					result++;
					while (!a.empty())
					{
						int x = a.front().first;
						int y = a.front().second;
						a.pop();
						if (dp[k][x - 1][y] == 1 && check[k][x - 1][y] == 0)
						{
							a.push({ x - 1, y });
							check[k][x-1][y] = 1;
						}
						if (dp[k][x + 1][y] == 1 && check[k][x + 1][y] == 0)
						{
							a.push({ x + 1, y });
							check[k][x+1][y] = 1;
						}
						if (dp[k][x][y-1] == 1 && check[k][x][y-1] == 0)
						{
							a.push({ x, y-1 });
							check[k][x][y-1] = 1;
						}
						if (dp[k][x][y+1] == 1 && check[k][x][y+1] == 0)
						{
							a.push({ x, y+1 });
							check[k][x][y+1] = 1;
						}
					}
				}
			}
		}
		if (result > max_result)
			max_result = result;
	}
	cout << max_result << endl;
	return 0;
}