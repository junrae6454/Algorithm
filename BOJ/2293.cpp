#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int coin[101];
int n, k;
long int dp[10001];

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j - coin[i] >= 0)
			{
				dp[j] += dp[j - coin[i]];
			}
		}
	}
	cout << dp[k];
	return 0;
}