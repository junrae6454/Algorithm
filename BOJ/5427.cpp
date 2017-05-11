#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string maps[1002];
int main()
{
	int testcase;
	scanf("%d", &testcase);

	vector<pair<int, int>> around;
	around.push_back({ 0,1 });
	around.push_back({ 1,0 });
	around.push_back({ 0,-1 });
	around.push_back({ -1,0 });
	for (int Testcase = 1; Testcase <= testcase; Testcase++)
	{
		int w, h;
		cin >> w >> h;
		vector<pair<int, int>> fire;
		vector<pair<int, int>> person;
		vector<pair<int, int>> exit;
		for (int i = 0; i < h; i++)
		{
			cin >> maps[i];
			for (int j = 0; j < w; j++)
			{
				if (maps[i][j] == '@')
				{
					person.push_back({ i,j });
				}
				else if (maps[i][j] == '*')
				{
					fire.push_back({ i,j });
				}
				if ((i == 0 || i == h-1 || j == 0 || j == w-1) && maps[i][j] == '.')
				{
					exit.push_back({ i,j });
				}
			}
		}
		if (person.front().first == 0 || person.front().first == h - 1 || person.front().second == 0 || person.front().second == w - 1)
		{
			cout << 1 << endl;
			continue;
		}
		if (exit.size() == 0)
		{//출구가 없는경우
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		
		int result = 0;
		bool die = false;
		while (++result && !die)
		{
			vector<pair<int, int>> nfire;
			vector<pair<int, int>> nperson;
			for (auto aexit : exit)
			{
				if (maps[aexit.first][aexit.second] == '@')
				{
					die = true;
					break;
				}
			}
			if (die) break;
			if (person.size() == 0)
			{
				result = -1;
				break;
			}
			for (auto aperson : person)
			{
				for (auto round : around)
				{
					if (aperson.first + round.first < 0 || aperson.first + round.first > h - 1 ||
						aperson.second + round.second < 0 || aperson.second + round.second > w - 1)
					{
						continue;
					}
					else
					{
						if (maps[aperson.first + round.first][aperson.second + round.second] == '.')
						{
							maps[aperson.first + round.first][aperson.second + round.second] = '@';
							nperson.push_back({ aperson.first + round.first,aperson.second + round.second });
						}
					}
				}
			}
			for (auto afire : fire)
			{
				for (auto round : around)
				{
					if (afire.first + round.first < 0 || afire.first + round.first > h - 1 ||
						afire.second + round.second < 0 || afire.second + round.second > w - 1)
					{
						continue;
					}
					else
					{
						if (maps[afire.first + round.first][afire.second + round.second] == '.' ||
							maps[afire.first + round.first][afire.second + round.second] == '@')
						{
							maps[afire.first + round.first][afire.second + round.second] = '*';
							nfire.push_back({ afire.first + round.first,afire.second + round.second });
						}
					}
				}
			}
			person = nperson;
			fire = nfire;
		}
		if (result < 0)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << result << endl;
	}
	return 0;
}