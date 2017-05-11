#include <cstdio>
#include <iostream>
#include <cstring>
int min(int a, int b)
{
	return a > b ? b : a;
}
using namespace std;
int room[52][52];
int dp[52][52];
int min4(int a, int b, int c, int d)
{
	return min(min(a, b), min(c,d));
}
int main()
{
	int N;
	cin >> N;
	memset(dp, 10, sizeof(dp));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int temp;
			scanf("%1d", &temp);
			room[i][j] = (temp + 1) % 2;
		}
	}
	dp[1][1] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if( dp[j][k] > min4(dp[j - 1][k], dp[j][k - 1], dp[j + 1][k], dp[j][k + 1]) + room[j][k])
					dp[j][k] = min4(dp[j - 1][k], dp[j][k - 1], dp[j + 1][k], dp[j][k + 1]) + room[j][k];
			}
		}
	}
	cout << dp[N][N] << endl;
	return 0;
}