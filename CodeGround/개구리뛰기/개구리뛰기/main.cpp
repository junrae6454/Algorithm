// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int map[1000001];
int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//	/*
	freopen("sample_input.txt", "r", stdin);
	//*/
	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &map[i]);
		}
		int K;
		scanf("%d", &K);
		int max = 0;
		int count = 1;
		for (int i = 1; i <= N; i++)
		{
			if (max + K < map[i])
			{
				if (map[i - 1] + K < map[i])
				{
					count = -1;
					break;
				}
				else
				{
					max = map[i - 1];
					count++;
				}
			}
		}
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%d\n", count);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}