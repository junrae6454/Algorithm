#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[2200][2200];
int input[2200];

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
	dp[0][0] = 1;
	int size;
	scanf("%d", &size);
	for (int i = 1; i <= size; i++)
	{
		scanf("%d", &input[i]);
	}

	int testcase;
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		dp[a][b] = ispalindrome(a, b);
		if (dp[a][b] == -1)
			printf("0\n");
		else
			printf("%d\n", dp[a][b]);
	}
}