#include <iostream>
using namespace std;

int book[300001];

int main()
{
	int size;
	cin >> size;

	for (int i = 1; i <= size; i++)
	{
		cin >> book[i];
	}
	bool findmax = false;
	int target = size;
	for (int i = size; i > 0; i--)
	{
		if (findmax)
		{
			if (book[i] == target)
			{
				target--;
			}
		}
		else
		{
			if (book[i] == size)
			{
				findmax = true;
				target = size - 1;
			}
		}
	}
	cout << target;
	return 0;
}