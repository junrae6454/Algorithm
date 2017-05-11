// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
	int N = 0;
	int score[300001];

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	int TC;
	int test_case;
	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		int k = 0, count=0;
		scanf("%d", &N);
		
		memset(score, 0, sizeof(score));

		for (int i = 0; i < N; i++)
			scanf("%d", &score[i]);

		sort(score, score + N, greater<int>());
		int max_score = 0;
		for (int i = 0; i < N; i++)
		{
			if (max_score < score[i] + i + 1)
				max_score = score[i] + i + 1;
		}
		for (int i = 0; i < N; i++)
		{
			if (max_score <= score[i] + N)
				count++;
		}
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%d\n", count);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}