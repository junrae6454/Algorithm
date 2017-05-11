#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[2500][2500];
char input[2501];
int dp2[2500];
int ispalindrome(int s, int e)
{//s start e end
	if (s > e)
	{
		int temp = s;
		s = e;
		e = temp;
	}
	if (s == e)
	{
		return dp[s][e] = 1;
	}
	else if (s + 1 == e)
	{
		if (input[s] == input[e])
		{
			return dp[s][e] = 1;
		}
		else
			return dp[s][e] = -1;
	}
	if (dp[s][e] != 0)
	{
		return dp[s][e];
	}
	if (input[s] == input[e])
	{
		return dp[s][e] = ispalindrome(s + 1, e - 1);
	}
	else
	{
		return dp[s][e] = -1;
	}
}

int main()
{
	scanf("%s", &input);
	int len = strlen(input);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			dp[i][j] = ispalindrome(i, j);
		}
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (dp[i][j] == -1)
				dp[i][j] = 0;
		}
	}
	dp2[0] = 0;
	
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <=i ; j++)
		{
			if (dp[j][i] == 1)
			{
				if(dp2[i] == 0 || dp2[i] > dp2[j - 1] + 1)
					dp2[i] = dp2[j - 1] + 1;
			}
		}
	}
	dp2[0] = 1;
	cout << dp2[len-1];
	return 0;
}