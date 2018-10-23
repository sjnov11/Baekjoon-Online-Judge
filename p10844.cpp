#include <iostream>
using namespace std;

int dp[101][10];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
	}

	int answer = 0;
	for (int i = 1; i <= 9; i++) {
		answer = (answer + dp[N][i]) % 1000000000;
	}
	cout << answer << endl;

}