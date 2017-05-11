#include <iostream>
#include <cstdio>

using namespace std;
int coin[111];
int dp[11111];

int counter()
{

	return 0;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &coin[i]);
	}
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j >= coin[i])
			{
				if (j == coin[i])
				{
					dp[j] = 1;
				}
				else if( dp[j-coin[i]] > 0)
				{
					if( dp[j] > dp[coin[i]] + dp[j - coin[i]] || dp[j] == 0)
						dp[j] = dp[coin[i]] + dp[j - coin[i]];
				}
			}
		}
	}
	if (dp[k] == 0)
	{
		cout << -1;
	}
	else
	{
		cout << dp[k];
	}
	return 0;
}