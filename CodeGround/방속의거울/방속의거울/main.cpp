// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	// /*
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
		int** map = new int*[N+2];
		int** check = new int*[N + 2];
		for (int i = 0; i < N+2; i++)
		{
			map[i] = new int[N+2];
			check[i] = new int[N + 2];
			memset(check[i], 0, sizeof(int)*(N + 2));
			memset(map[i], -1, sizeof(int)*(N+2));
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				scanf("%1d", &map[i][j]);
			}
		}

		int x = 1, y = 0;
		int direction = 0;//0�� 1�� 2�� 3��
		int count = 0;
		while (1)
		{
			while (1)
			{
				if (direction == 0)
				{
					y++;
				}
				else if (direction == 1)
				{
					x++;
				}
				else if (direction == 2)
				{
					y--;
				}
				else if (direction == 3)
				{
					x--;
				}
				if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == -1)
					break;
			} 

			if (map[x][y] == 1)
			{
				direction = 3 - direction;
			}
			else if (map[x][y] == 2)
			{
				if (direction % 2 == 0)
				{
					direction += 1;
				}
				else
				{
					direction -= 1;
				}
			}
			else if( map[x][y] == -1)
			{
				break;
			}

			if (check[x][y] == 0)
			{
				count++;
				check[x][y] = -1;
			}
		}
		
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%d\n", count);
		for (int i = 0; i < N; i++)
		{
			delete[] check[i];
			delete[] map[i];
		}
		delete[] map;
		delete[] check;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}