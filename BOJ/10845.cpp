#include <iostream>
#include <queue>
#include <string>
using namespace std;
/*
push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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