#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int maps[1002][1002];
int dp[3][1002][1002];
//int maps[7][7];
//int dp[3][7][7];

int N, M;

int max2(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int max3(int a, int b, int c)
{
	return max2(max2(a, b), c);
}
int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> maps[i][j];
		}
	}
	
	memset(dp, -10, sizeof(dp));

	dp[0][1][1] = maps[1][1];
	dp[1][1][1] = maps[1][1];
	dp[2][1][1] = maps[1][1];
	
	for (int j = 1; j <= M; j++)
	{
		int i = 1;
		if (dp[1][i][j] < max2(dp[0][i][j - 1], dp[1][i][j - 1]) + maps[i][j])
		{
			dp[0][i][j] = max2(dp[0][i][j - 1], dp[1][i][j - 1]) + maps[i][j];
			dp[1][i][j] = max2(dp[0][i][j - 1], dp[1][i][j - 1]) + maps[i][j];
			dp[2][i][j] = max2(dp[0][i][j - 1], dp[1][i][j - 1]) + maps[i][j];
		}
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{//0위에서 1 왼쪽에서 2 오른쪽에서
			if (dp[0][i][j] < max3(dp[0][i - 1][j], dp[1][i - 1][j], dp[2][i - 1][j]) + maps[i][j])
				dp[0][i][j] = max3(dp[0][i - 1][j], dp[1][i - 1][j], dp[2][i - 1][j]) + maps[i][j];
		}
		dp[1][i][1] = dp[0][i][1];
		for (int j = 1; j <= M; j++)
		{//0위에서 1 왼쪽에서 2 오른쪽에서
			if (dp[1][i][j] < max2(dp[0][i][j - 1], dp[1][i][j - 1]) + maps[i][j])
				dp[1][i][j] = max2(dp[0][i][j - 1], dp[1][i][j - 1]) + maps[i][j];
		}
		dp[1][i][M] = dp[0][i][M];
		for (int j = M; j > 0; j--)
		{
			if (dp[2][i][j] < max2(dp[0][i][j + 1], dp[2][i][j + 1]) + maps[i][j])
				dp[2][i][j] = max2(dp[0][i][j + 1], dp[2][i][j + 1]) + maps[i][j];
		}
	}

	cout << max3(dp[0][N][M], dp[1][N][M], dp[2][N][M]) << endl;
	return 0;
}