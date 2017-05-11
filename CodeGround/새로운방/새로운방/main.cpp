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
	/* 아래 freopen 함수는 sample_input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	// /*
	freopen("sample_input.txt", "r", stdin);
	//*/
	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n", min(dp[N][N][0], dp[N][N][1]));
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}