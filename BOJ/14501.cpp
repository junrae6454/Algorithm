#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int plan[15][3];
	int dp[16];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> plan[i][0] >> plan[i][1];
		if (i + plan[i][0] > N)
		{
			plan[i][0] = 0;
			plan[i][1] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		plan[i][2] = i + plan[i][0];
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (plan[j][2] == i)
			{
				if( dp[i] < plan[j][1] + dp[plan[j][2] - plan[j][0]])
					dp[i] = plan[j][1] + dp[plan[j][2] - plan[j][0]];
			}
			if (dp[i] < dp[i - 1])
			{
				dp[i] = dp[i - 1];
			}
		}
	}
	
	int result = 0;

	for (int i = 0; i < N+1; i++)
	{
		if (result < dp[i])
		{
			result = dp[i];
		}
	}
	cout << result << endl;
	return 0;
}