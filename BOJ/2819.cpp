#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;

map<long long int, long long int> mapx;
map<long long int, long long int> mapy;

int main()
{
	int x = 0, y = 0;

	int N, M;
	scanf("%lld %lld", &N, &M);
	long long int sumx = 0;
	long long int sumy = 0;
	long long int s_x = 0;
	long long int e_x = 0;
	long long int l_x = 0;
	long long int s_y = 0;
	long long int e_y = 0;
	long long int l_y = 0;

	for (long long int i = 0; i < N; i++)
	{
		long long int tempx, tempy;
		scanf("%lld %lld", &tempx, &tempy);
		mapx[tempx]++;
		mapy[tempy]++;
		sumx += abs(tempx);
		sumy += abs(tempy);
		if (tempx == 0)
			++e_x;
		else if (tempx < 0)
			++s_x;
		else if (tempx > 0)
			++l_x;

		if (tempy == 0)
			++e_y;
		else if (tempy < 0)
			++s_y;
		else if (tempy > 0)
			++l_y;
	}
	string order;
	cin >> order;

	for (int i = 0; i < M; i++)
	{	//S(north)는(x, y + 1)로, J(south)는(x, y - 1)로, I(east)는(x + 1, y)로, Z(west)는(x - 1, y)
		long long int res = 0;
		if (order[i] == 'S')
		{
			++y;
			sumy += e_y;
			sumy += s_y;
			sumy -= l_y;
			s_y += e_y;
			e_y = mapy[y];
			l_y -= mapy[y];
		}
		else if (order[i] == 'J')
		{
			--y;			
			sumy += e_y;
			sumy -= s_y;
			sumy += l_y;
			s_y -= e_y;
			e_y = mapy[y];
			l_y += mapy[y];
		}
		else if (order[i] == 'I')
		{
			++x;
			sumx += e_x;
			sumx += s_x;
			sumx -= l_x;
			s_x += e_x;
			e_x = mapx[x];
			l_x -= mapx[x];
		}
		else if (order[i] == 'Z')
		{
			--x;
			sumx += e_x;
			sumx -= s_x;
			sumx += l_x;
			s_x -= e_x;
			e_x = mapx[x];
			l_x += mapx[x];
		}
		printf("%lld\n", sumx+sumy);
	}
	return 0;
}