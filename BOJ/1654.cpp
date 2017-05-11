#include <iostream>
#include <cstdio>

#define _CRT_SECURE_NO_WARNINGS
int count;
int input[10001];
int main()
{
	long int size;
	long int max = 0;
	scanf("%d %d", &size, &count);

	for (int i = 0; i < size; i++)
	{
		scanf("%d", &input[i]);
		if (max < input[i])
			max = input[i];
	}
	long int result;
	long int left = 0;
	long int right = max;
	while (left <= right)
	{
		long int mid = (left + right) / 2;
		result = 0;
		for (int i = 0; i < size; i++)
		{
			result += input[i] / mid;
		}
		if (result < count)
		{
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}
	}
	printf("%d", right);
	return 0;
}