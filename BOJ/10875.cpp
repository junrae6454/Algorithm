#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

long long int min(long long int a, long long int b)
{
	if (a > b)
		return b;
	else
		return a;
}
long long int max(long long int a, long long int b)
{
	if (a > b)
		return a;
	else
		return b;
}

vector<pair<pair<long long int, long long int >, pair<long long int, long long int>>> vline;//세로줄
vector<pair<pair<long long int, long long int >, pair<long long int, long long int>>> hline;//가로줄

int direction = 0; //0 동 1 남 2 서 3 북
int nextstep[4][2] = { { 1,0 },{ 0,-1 },{ -1,0 },{ 0,1 } };
bool dead = false;
long long int iscrashed(long long int sx, long long int sy, long long int ex, long long int ey)
{
	long long int minlength = 0;
	for (auto it : vline)
	{
		if (direction % 2 == 0 && it == vline.back())
			break;
		if (it.first.first >= min(sx, ex) && it.first.first <= max(sx, ex))
		{//sx ex 사이에 세로직선 존재  
			if ((min(it.first.second, it.second.second) <= ey &&max(it.first.second, it.second.second) >= ey) || // 도착점이 이미지나간선분 중간인경우
				(min(sy, ey) <= min(it.first.second, it.second.second) && max(sy, ey) >= max(it.first.second, it.second.second) && sx == it.first.first))// 도착점이 선분을 감쌀때
			{
				if ((minlength == 0 || minlength > abs(it.first.first - sx)) && direction % 2 == 0)
				{
					minlength = abs(it.first.first - sx);
				}
				else if (it.first.first == sx && direction % 2 == 1)
				{
					if (minlength == 0 || minlength > min(abs(it.first.second - sy), abs(it.second.second - sy)))
					{
						minlength = min(abs(it.first.second - sy), abs(it.second.second - sy));
					}
				}
				dead = true;
			}
		}
	}
	for (auto it : hline)
	{
		if (direction % 2 == 1 && it == hline.back())
			break;
		if (it.first.second >= min(sy, ey) && it.first.second <= max(sy, ey))
		{
			if ((min(it.first.first, it.second.first) <= ex &&max(it.first.first, it.second.first) >= ex) ||
				(min(sx, ex) <= min(it.first.first, it.second.first) && max(sx, ex) >= max(it.first.first, it.second.first) && sy == it.first.second))
			{
				if ((minlength == 0 || minlength > abs(it.first.second - sy)) && direction % 2 == 1)
				{
					minlength = abs(it.first.second - sy);
				}
				else if (it.first.second == sy && direction % 2 == 0)
				{
					if (minlength == 0 || minlength > min(abs(it.first.first - sx), abs(it.second.first - sx)))
					{
						minlength = min(abs(it.first.first - sx), abs(it.second.first - sx));
					}
				}
				dead = true;
			}
		}
	}

	return minlength - 1;
}
int main()
{
	long long int L, N;
	cin >> L;
	cin >> N;
	long long int eline = L + 1;
	long long int body = 1;
	vline.push_back({ { eline, eline },{ eline,-eline } });
	vline.push_back({ { -eline, eline },{ -eline,-eline } });
	hline.push_back({ { eline, eline },{ -eline,eline } });
	hline.push_back({ { eline, -eline },{ -eline,-eline } });
	long long int sx, sy, ex, ey;
	sx = sy = ex = ey = 0;
	for (long long int i = 0; i < N; i++)
	{
		long long int time;
		char face;
		cin >> time >> face;

		ex = sx + time*nextstep[direction][0];
		ey = sy + time*nextstep[direction][1];
		long long int deadlength = iscrashed(sx, sy, ex, ey);
		if (dead)
		{
			body += deadlength;
			cout << body << endl;
			return 0;
		}
		else
		{
			body += time;
			if (direction % 2 == 0)
			{
				hline.push_back({ {sx,sy}, {ex,ey} });
			}
			else
			{
				vline.push_back({ { sx,sy },{ ex,ey } });
			}
			sx = ex;
			sy = ey;
		}
		if (face == 'L')
		{
			direction = (direction + 3) % 4;
		}
		else
		{
			direction = (direction + 1) % 4;
		}
	}

	ex = ex + nextstep[direction][0] * 3 * L;
	ey = ey + nextstep[direction][1] * 3 * L;
	body += iscrashed(sx, sy, ex, ey);
	
	cout << body << endl;
	return 0;
}