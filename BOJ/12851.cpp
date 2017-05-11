#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 200000;
bool check[MAX + 1];
int dist[MAX + 1];
int main()
{
	int N = 0, K = 0;		//N = ¼öºó K =µ¿»ý

	cin >> N >> K;
	check[N] = true;
	dist[N] = 0;
	queue<int> q1;
	queue<int> q2;
	queue<int> q3;
	memset(dist, 11, sizeof(dist));
	q1.push(N);
	bool find = false;
	bool save = false;
	int flag = 999999;
	dist[N] = 0;
	while (!q1.empty() && flag--)
	{
		int now = q1.front();
		if (K == now - 1 || now + 1 == K || now * 2 == K)
		{
			find = true;
			flag = 0;
		}
		q1.pop();
		if (now - 1 >= 0)
		{
			if (dist[now - 1] >= dist[now] + 1)
			{
				q2.push(now - 1);
				dist[now - 1] = dist[now] + 1;
			}
		}

		if (now + 1 < MAX)
		{
			if (dist[now + 1] >= dist[now] + 1)
			{
				q2.push(now + 1);
				dist[now + 1] = dist[now] + 1;
			}
		}

		if (now * 2 < MAX)
		{
			if (dist[now * 2] >= dist[now] + 1)
			{
				q2.push(now * 2);
				dist[now * 2] = dist[now] + 1;
			}
		}
		if (q1.empty())
		{
			q1 = q2;
			if (!find || q3.size() == 0)
			{
				q3 = q2;
			}
			while (!q2.empty())
				q2.pop();
		}
	}
	int path = 0;
	while (!q3.empty())
	{
		if (dist[K] == 1)
		{
			if (q3.front() == K)
				path++;
		}
		else if (q3.front() - 1 == K || q3.front() + 1 == K || q3.front() * 2 == K)
			path++;
		q3.pop();
	}
	if (N == K)
	{
		cout << 0 << '\n' << 1 << endl;
	}
	else
		cout << dist[K] << '\n' << path << endl;
	return 0;
}
