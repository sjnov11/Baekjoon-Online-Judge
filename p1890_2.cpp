#include <iostream>
using namespace std;
int map[101][101];
long long dp[101][101];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0) continue;
			if (i + map[i][j] <= N)
				dp[i + map[i][j]][j] += dp[i][j];
			if (j + map[i][j] <= N)
				dp[i][j + map[i][j]] += dp[i][j];
		}
	}

	cout << dp[N][N] << endl;
}