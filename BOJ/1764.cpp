#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//vector<string> input;
vector<string> result;
map<string, int> input;
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		char temp2[30];
		scanf("%s", temp2);
		string temp = temp2;
		input[temp] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		char temp0[30];
		scanf("%s", temp0);
		string temp = temp0;
		if (input.find(temp) != input.end())
			result.push_back(temp);
	}
	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (auto temp = result.begin(); temp != result.end(); ++temp)
	{
		cout << *temp << endl;
	}
	return 0;
}