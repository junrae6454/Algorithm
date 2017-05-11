#include <iostream>
#include <cstdio>

using namespace std;
/*
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10
*/

int route = 0;
int map[510][510];
int dp[510][510];
int M, N;

int counter(int i, int j)
{
	if (i == M && j == N)
		route++;
	int t = map[i][j];
	int a = map[i - 1][j];
	int b = map[i + 1][j];
	int c = map[i][j - 1];
	int d = map[i][j + 1];

	if (t > a) { counter(i - 1, j); }
	if (t > b) { counter(i + 1, j); }
	if (t > c) { counter(i, j - 1); }
	if (t > d) { counter(i, j + 1); }
	return 0;
}
int main()
{
	cin >> M >> N;
	for (int i = 0; i <= M+1; i++)
	{
		for (int j = 0; j <= N+1; j++)
		{
			map[i][j] = 999999;
		}
	}
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d",&map[i][j]);
		}
	}

	counter(1,1);
	cout << route;

	return 0;
}
#include <cstdio>
int n, m;
int a[500][500];
int d[500][500];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int go(int x, int y) {
	if (x == n - 1 && y == m - 1) {
		return 1;
	}
	if (d[x][y]) {
		return d[x][y];
	}
	int &ans = d[x][y];
	for (int k = 0; k<4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (a[x][y] > a[nx][ny]) {
				ans += go(nx, ny);
			}
		}
	}
	return ans;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d\n", go(0, 0));
	
	return 0;
}

