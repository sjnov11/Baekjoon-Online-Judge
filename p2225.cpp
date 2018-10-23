#include <iostream>
using namespace std;

int dp[201][201];

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i <= K; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= N; i++)
		dp[i][1] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			for (int k = 0; k <= i; k++) {
				dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) %1000000000;
			}
		}
	}
	cout << dp[N][K] << endl;
}