#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int maps[500][500];

int result = 0;
int N, M;

int go(int x, int y, int count, int sum, int check[][500])
{
	int nextsum = sum + maps[x][y];

	if (count == 4)
	{
		if (result < nextsum)
		{
			result = nextsum;
		}
		return 0;
	}

	if (count == 3)
	{
		if (x - 1 >= 0 && y - 1 >= 0)
		{
			if (nextsum + maps[x - 1][y - 1] > result && check[x - 1][y - 1] == 0 && (check[x][y - 1] == 1 || check[x - 1][y] == 1))
			{
				result = nextsum + maps[x - 1][y - 1];
				return 0;
			}
		}
		if (x - 1 >= 0 && y + 1 < M)
		{
			if (nextsum + maps[x - 1][y + 1] > result && check[x - 1][y + 1] == 0 && (check[x][y + 1] == 1 || check[x - 1][y] == 1))
			{
				result = nextsum + maps[x - 1][y + 1];
				return 0;
			}
		}
		if (x + 1 < N && y - 1 >= 0)
		{
			if (nextsum + maps[x + 1][y - 1] > result && check[x + 1][y - 1] == 0 && (check[x][y - 1] == 1 || check[x + 1][y] == 1))
			{
				result = nextsum + maps[x + 1][y - 1];
				return 0;
			}
		}
		if (x + 1 < N && y + 1 < M)
		{
			if (nextsum + maps[x + 1][y + 1] > result && check[x + 1][y + 1] == 0 && (check[x][y + 1] == 1 || check[x + 1][y] == 1))
			{
				result = nextsum + maps[x + 1][y + 1];
				return 0;
			}
		}
	}

	if (x - 1 >= 0)
	{
		if (check[x - 1][y] == 0)
		{
			check[x - 1][y] = 1;
			go(x - 1, y, count + 1, nextsum, check);
			check[x - 1][y] = 0;
		}
	}
	if (y - 1 >= 0)
	{
		if (check[x][y - 1] == 0)
		{
			check[x][y - 1] = 1;
			go(x, y - 1, count + 1, nextsum, check);
			check[x][y - 1] = 0;
		}
	}
	if (x + 1 < N)
	{
		if (check[x + 1][y] == 0)
		{
			check[x + 1][y] = 1;
			go(x + 1, y, count + 1, nextsum, check);
			check[x + 1][y] = 0;
		}
	}
	if (y + 1 < M)
	{
		if (check[x][y + 1] == 0)
		{
			check[x][y + 1] = 1;
			go(x, y + 1, count + 1, nextsum, check);
			check[x][y + 1] = 0;
		}
	}
}

int main()
{

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maps[i][j];
		}
	}
	int check[500][500];
	memset(check, 0, sizeof(check));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			check[i][j] = 1;
			go(i, j, 1, 0, check);
			check[i][j] = 0;
		}
	}
	cout << result;

	return 0;
}