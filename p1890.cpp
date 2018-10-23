#include <iostream>
#include <string.h>
using namespace std;

long long dp[100][100];
int map[100][100];
int N;


long long solve(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) {
		//dp[x][y] = 0;
		return 0;
	}
	
	if (dp[x][y] != -1)
		return dp[x][y];

	if (map[x][y] == 0) {
		return 0;
	}
	else {
		dp[x][y] = solve(x, y + map[x][y]) + solve(x + map[x][y], y);
	}
	return dp[x][y];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(long long) * 100 * 100);
	dp[N - 1][N - 1] = 1;
	solve(0, 0);

	/*dp[N - 1][N - 1] = 1;
	for (int i = N-1; i >=0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (i == N - 1 && j == N - 1) continue;
			if (i + map[i][j] < N)
				dp[i][j] += dp[i + map[i][j]][j];
			if (j + map[i][j] < N) {
				dp[i][j] += dp[i][j + map[i][j]];
			}
		}
	}*/
	cout << dp[0][0] << "\n";

}