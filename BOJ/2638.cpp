#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <iterator>

using namespace std;
int maps[102][102];

int main()
{
	memset(maps, 1, sizeof(maps));
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> around;
	around.push_back({ 0,1 });
	around.push_back({ 1,0 });
	around.push_back({ 0,-1 });
	around.push_back({ -1,0 });
	deque<pair<int, int>> cheeze;
	vector<pair<int, int>> outside;
	outside.push_back({ 1, 1 });

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 1)
				cheeze.push_back({ i,j });
		}
	}
	maps[1][1] = -1;
	vector<pair<int, int>> noutside;

	while (!outside.empty())
	{
		int x, y;
		x = outside.back().first;
		y = outside.back().second;
		outside.pop_back();
		for (auto it : around)
		{
			if (maps[x + it.first][y + it.second] == 0)
			{
				maps[x + it.first][y + it.second] = -1;
				noutside.push_back({ x + it.first, y + it.second });
			}
		}
		if (outside.empty())
		{
			outside = noutside;
			noutside.clear();
		}
	}
	int result = 0;
	while (++result)
	{
		deque<pair<int, int>> melt;
		deque<pair<int, int>> nmelt;
		for(int i=0; i<cheeze.size(); i++)
		{
			int x, y;
			x = cheeze[i].first;
			y = cheeze[i].second;
			int count = 0;
			for (auto it : around)
			{
				if (maps[x + it.first][y + it.second] == -1)
				{
					count++;
				}
			}
			if (count >= 2)
			{
				melt.push_back({ x, y });
				maps[x][y] = 2;
				cheeze.erase(cheeze.begin()+i--);
			}
		}
		while (!melt.empty())
		{
			int x, y;
			x = melt.front().first;
			y = melt.front().second;
			melt.pop_front();
			maps[x][y] = -1;
			for (auto it : around)
			{
				if (maps[x + it.first][y + it.second] == 0)
				{
					maps[x + it.first][y + it.second] = -1;
					nmelt.push_back({ x + it.first, y + it.second });
				}
			}
			if (melt.empty())
			{
				melt = nmelt;
				nmelt.clear();
			}
		}
		if (cheeze.size() == 0)
			break;
	}
	cout << result << endl;
	

	return 0;
}