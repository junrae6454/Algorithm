#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int map[102][102];
int result = 0;
void RemoveMine(int x, int y)
{
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (map[i][j] > 0)
				map[i][j]--;
		}
	}
	result++;
}
int main()
{
	int size;

	cin >> size;
	for (int i = 1; i <= size; i++)
	{
		char temp[101];
		cin >> temp;
		for (int j = 1; j <= strlen(temp); j++)
		{
			if (temp[j-1] == '#')
				map[i][j] = -1;
			else
			{
				map[i][j] = (int)(temp[j-1])-48;
			}
		}
	}
	/*for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			cout.width(3);
			cout << map[i][j];
		}
		cout << endl;
	}*/
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if( map[i][j] == 0)
			{
				for (int a = i - 1; a <= i + 1; a++)
				{
					for (int b = j - 1; b <= j + 1; b++)
					{
						if (map[a][b] == -1)
							map[a][b] = -2;
					}
				}
			}
			else
			{
				int count = 0;
				for (int a = i - 1; a <= i + 1; a++)
				{
					for (int b = j - 1; b <= j + 1; b++)
					{
						if (map[a][b] == -1)
							count++;
					}
				}
				if (count == map[i][j])
				{
					for (int a = i - 1; a <= i + 1; a++)
					{
						for (int b = j - 1; b <= j + 1; b++)
						{
							if (map[a][b] == -1)
							{
								RemoveMine(a, b);
								map[a][b] = -2;
							}
						}
					}
				}
			}
			}
	}
	/*for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			cout.width(3);
			cout << map[i][j];
		}
		cout << endl;
	}*/
	if (size > 4)
	{
		result += (size - 4)*(size - 4);
	}
	cout << result;
	return 0;
}