#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int result = 0;
	int result2 = 0;
	for (int i = 0; i < 10; i++)
	{
		int temp;
		cin >> temp;
		if (result < 100)
		{
			result2 = result;
			result += temp;
		}
	}
	if (abs(100 - result) <= abs(100 - result2))
		cout << result;
	else
		cout << result2;

	return 0;
}