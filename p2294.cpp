#include <iostream>
using namespace std;

int dp[10001];
int coin[101];

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}
	for (int i = 0; i <= K; i++) {
		dp[i] = -1;
	}
	dp[0] = 0;
	for (int i = 1; i <= K; i++) {
		int min_cnt = 99999999;
		for (int j = 1; j <= N; j++) {
			if (i - coin[j] < 0) continue;
			if (dp[i - coin[j]] == -1) continue;
			if (min_cnt > dp[i - coin[j]] + 1) {
				min_cnt = dp[i - coin[j]] + 1;
				dp[i] = min_cnt;
			}
		}
	}
	cout << dp[K] << "\n";
}