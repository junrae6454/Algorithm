#include <iostream>
#include <cstdio>
using namespace std;
long long int result;
int people[1000000];
int main()
{
	int room;
	scanf("%d",&room);
	for (int i = 0; i < room; i++)
	{
		scanf("%d", &people[i]);
	}
	int major, minor;
	scanf("%d %d", &major, &minor);

	result = room;

	for (int i = 0; i < room; i++)
	{
		int rest = ((people[i] - major) > 0 && (people[i] - major) % minor) > 0 ? 1 : 0;
		result += (((people[i]-major)>0?(people[i] - major):0)/minor)+rest;
	}
	cout << result << endl;
	return 0;
}