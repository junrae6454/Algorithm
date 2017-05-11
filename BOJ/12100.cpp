#include <iostream>

using namespace std;

int result = -1;
int s;//size
int loop = 1;
void go(int maptemp[][20], int direction, int count)
{//1 동 2 서 3 북 4 남
	//cout << loop++ << " : " << count << endl;

	int map[20][20];
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			map[i][j] = maptemp[i][j];
		}
	}

	if (direction == 1)
	{
		for (int i = 0; i < s; i++)
		{
			int y = s - 1;
			int j = s - 1;
			while (map[i][j] == 0)
			{
				if (j == 0) break;
				else j--;
			}
			for (int k = j - 1; k >= 0 && j > 0; k--)
			{
				if (map[i][j] != map[i][k] && map[i][k] != 0)
				{//다른숫자를 만난경우
					map[i][y] = map[i][j];
					if (y != j)
					{
						map[i][j] = 0;
					}
					y--;
					j = k;
					while (map[i][j] == 0)
					{
						if (j == 0) break;
						else j--;
					}
					k = j;
				}
				else if (map[i][k] == map[i][j] && k != j)
				{
					map[i][y] = map[i][k] * 2;
					if (map[i][y] > result)
						result = map[i][y];
					if (y != j)
					{
						map[i][j] = 0;
					}
					map[i][k] = 0;
					y--;
					j = k;
					while (map[i][j] == 0)
					{
						if (j == 0) break;
						else j--;
					}
					k = j;
				}
			}
			map[i][y] = map[i][j];
			if (y != j)
			{
				map[i][j] = 0;
			}
		}
	}
	else if (direction == 2)
	{
		for (int i = 0; i < s; i++)
		{
			int y = 0;
			int j = 0;
			while (map[i][j] == 0)
			{
				if (j == s - 1) break;
				else j++;
			}
			for (int k = 0; k < s && j < s; k++)
			{
				if (map[i][j] != map[i][k] && map[i][k] != 0)
				{//다른숫자를 만난경우
					map[i][y] = map[i][j];
					if (y != j)
					{
						map[i][j] = 0;
					}
					y++;
					j = k;
					while (map[i][j] == 0)
					{
						if (j == s - 1) break;
						else j++;
					}
					k = j;
				}
				else if (map[i][k] == map[i][j] && k != j)
				{
					map[i][y] = map[i][k] * 2;
					if (map[i][y] > result)
						result = map[i][y];
					if (y != j)
					{
						map[i][j] = 0;
					}
					map[i][k] = 0;
					y++;
					j = k;
					while (map[i][j] == 0)
					{
						if (j == s - 1) break;
						else j++;
					}
					k = j;
				}
			}
			map[i][y] = map[i][j];
			if (y != j)
			{
				map[i][j] = 0;
			}
		}
	}
	else if (direction == 3)
	{
		for (int i = 0; i < s; i++)
		{
			int y = s - 1;
			int j = s - 1;
			while (map[j][i] == 0)
			{
				if (j == 0) break;
				else j--;
			}
			for (int k = j - 1; k >= 0 && j > 0; k--)
			{
				if (map[j][i] != map[k][i] && map[k][i] != 0)
				{//다른숫자를 만난경우
					map[y][i] = map[j][i];
					if (y != j)
					{
						map[j][i] = 0;
					}
					y--;
					j = k;
					while (map[j][i] == 0)
					{
						if (j == 0) break;
						else j--;
					}
					k = j;
				}
				else if (map[k][i] == map[j][i] && k != j)
				{
					map[y][i] = map[k][i] * 2;
					if (map[y][i] > result)
						result = map[y][i];
					if (y != j)
					{
						map[j][i] = 0;
					}
					map[k][i] = 0;
					y--;
					j = k;
					while (map[j][i] == 0)
					{
						if (j == 0) break;
						else j--;
					}
					k = j;
				}
			}
			map[y][i] = map[j][i];
			if (y != j)
			{
				map[j][i] = 0;
			}
		}
	}
	else if (direction == 4)
	{
		for (int i = 0; i < s; i++)
		{
			int y = 0;
			int j = 0;
			while (map[j][i] == 0)
			{
				if (j == s - 1) break;
				else j++;
			}
			for (int k = 0; k < s && j < s; k++)
			{
				if (map[j][i] != map[k][i] && map[k][i] != 0)
				{//다른숫자를 만난경우
					map[y][i] = map[j][i];
					if (y != j)
					{
						map[j][i] = 0;
					}
					y++;
					j = k;
					while (map[j][i] == 0)
					{
						if (j == s - 1) break;
						else j++;
					}
					k = j;
				}
				else if (map[k][i] == map[j][i] && k != j)
				{
					map[y][i] = map[k][i] * 2;
					if (map[y][i] > result)
						result = map[y][i];
					if (y != j)
					{
						map[j][i] = 0;
					}
					map[k][i] = 0;
					y++;
					j = k;
					while (map[j][i] == 0)
					{
						if (j == s - 1) break;
						else j++;
					}
					k = j;
				}
			}
			map[y][i] = map[j][i];
			if (y != j)
			{
				map[j][i] = 0;
			}
		}
	}

	if (count + 1 < 5)
	{
		go(map, 1, count + 1);
		go(map, 2, count + 1);
		go(map, 3, count + 1);
		go(map, 4, count + 1);
	}
	return;
}

int main()
{
	cin >> s;
	int map[20][20];
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cin >> map[i][j];
			if (result < map[i][j])
				result = map[i][j];
		}
	}
	if (s == 1)
	{
		cout << map[0][0] << endl;
		return 0;
	}
	go(map, 1, 0);
	go(map, 2, 0);
	go(map, 3, 0);
	go(map, 4, 0);
	cout << result << endl;
	return 0;
}