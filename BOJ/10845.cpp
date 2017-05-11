#include <iostream>
#include <queue>
#include <string>
using namespace std;
/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
int main()
{
	queue<int> Q;
	int N;
	cin >> N;
	while (N--)
	{
		string temp;
		cin >> temp;
		if (temp == "push")
		{
			int temp2;
			cin >> temp2;
			Q.push(temp2);
		}
		else if (temp == "pop")
		{
			if (!Q.empty())
			{
				cout << Q.front() << endl;
				Q.pop();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (temp == "size")
		{
			cout << Q.size() << endl;
		}
		else if (temp == "empty")
		{
			cout << Q.empty() << endl;
		}
		else if (temp == "front")
		{
			if (!Q.empty())
			{
				cout << Q.front() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (temp == "back")
		{
			if (!Q.empty())
			{
				cout << Q.back() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
	return 0;
}