#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	// /*
	freopen("sample_input.txt", "r", stdin);
	//*/
	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		int map[101][101];
		int dp[101][101][2];
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				scanf("%d",&map[i][j]);
				int temp = map[i][j];
				int count2 = 0;
				int count3 = 0;
				while (temp % 2 == 0)
				{
					count2++;
					temp = temp / 2;
				}
				while (temp % 3 == 0)
				{
					count3++;
					temp = temp / 3;
				}
				int bigx,bigy;
				if (min(dp[i - 1][j][0]+count2, dp[i - 1][j][1]+count3) > min(dp[i][j - 1][0] + count2, dp[i][j - 1][1] + count3))
				{
					bigx = i - 1;
					bigy = j;
				}
				else if(min(dp[i - 1][j][0] + count2, dp[i - 1][j][1] + count3) < min(dp[i][j - 1][0] + count2, dp[i][j - 1][1] + count3))
				{
					bigx = i;
					bigy = j - 1;
				}
				else
				{
					if (max(dp[i - 1][j][0] + count2, dp[i - 1][j][1] + count3) > max(dp[i][j - 1][0] + count2, dp[i][j - 1][1] + count3))
					{
						bigx = i - 1;
						bigy = j;
					}
					else
					{
						bigx = i;
						bigy = j-1;
					}
				}
				dp[i][j][0] = dp[bigx][bigy][0]+count2;
				dp[i][j][1] = dp[bigx][bigy][1]+count3;
			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", min(dp[N][N][0], dp[N][N][1]));
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}