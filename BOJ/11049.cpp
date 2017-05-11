#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long int input[520][2];
long long int dp[520][520];

long long int go(int a, int b)
{
	if (a == b)
	{
		dp[a][b] = 0;
		return 0;
	}
	else if (dp[a][b] != -1)
	{
		return dp[a][b];
	}
	else if (a + 1 == b)
	{
		return dp[a][b] = input[a][0] * input[a][1] * input[b][1];
	}
	else
	{
		long long int min = dp[a][b];
		for (int i = a; i < b; i++)
		{
			int t1 = go(a, i);
			int t2 = go(i + 1, b);
			min = t1+ t2+ input[a][0] * input[i][1] * input[b][1];
			if (min < dp[a][b] || dp[a][b] == -1)
			{
				dp[a][b] = min;
			}
		}
		return min;
	}
}
int main()
{
	int size;
	scanf("%d", &size);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= size; i++)
	{
		scanf("%d %d", &input[i][0], &input[i][1]);
	}
	go(1, size);
	cout << dp[1][size];
}
