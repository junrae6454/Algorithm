#include <iostream>

using namespace std;

int main()
{
	long long int input;
	cin >> input;
	long long int i = 1;
	while (1)
	{
		if (((i + 1)*i) / 2 > input)
		{
			break;
		}
		else
			i++;
	}
	cout << i-1;
	return 0;
}