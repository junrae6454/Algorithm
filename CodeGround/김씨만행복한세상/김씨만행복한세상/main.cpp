#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <iterator>

using namespace std;

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		vector<int> border[1001];
		int check[201];
		memset(check, -1, sizeof(check));
		int N, I;

		scanf("%d", &N);
		scanf("%d", &I);
		for (int i = 1; i <= I; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			border[a].push_back(b);
			border[b].push_back(a);
		}
		int result = 1;
		queue<int> list;
		list.push(1);
		check[1] = 1;
		int king = 0;
		bool exit = false;

		while (!list.empty())
		{
			int now = list.front();
			list.pop();
			king = (check[now] + 1) % 2;
			
			for (int i = 0; i < border[now].size(); i++ )
			{
				int it = border[now][i];
				if (check[it] == -1 )
				{
					check[it] = king;
					list.push(it);
				}
				else if (check[it] == check[now])
				{
					result = 0;
					exit = true;
				}
				if (exit)
					break;
			}
			if (exit)
				break;
		}
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", result);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}