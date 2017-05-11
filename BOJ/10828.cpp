#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	stack<int> Stack;
	while (N--)
	{
		string temp;
		cin >> temp;
		if (temp == "push")
		{
			int temp2;
			cin >> temp2;
			Stack.push(temp2);
		}
		else if (temp == "pop")
		{
			if (!Stack.empty())
			{
				cout << Stack.top() << endl;
				if (Stack.top())
					Stack.pop();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (temp == "size")
		{
			cout << Stack.size() << endl;
		}
		else if (temp == "empty")
		{
			cout << Stack.empty() << endl;
		}
		else if (temp == "top")
		{
			if (!Stack.empty())
			{
				cout << Stack.top() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
	return 0;
}