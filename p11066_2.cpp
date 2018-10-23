#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int total[501];
int dp[501][501];

int main() {
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int K;
		cin >> K;

		for (int i = 1; i <= K; i++) {
			int page;
			cin >> page;
			total[i] = total[i - 1] + page;
		}

		for (int i = 1; i <= K; i++) {
			dp[i][i] = 0;
		}


		for (int l = 1; l < K; l++) {
			for (int i = 1; i <= K - l; i++) {
				int sum = 0;
				/*for (int j = i; j <= i + l; j++) {
					sum += page[j];
				}*/
				int val = 99999999;
				for (int j = i; j <= i + l - 1; j++) {
					val = min(val, dp[i][j] + dp[j + 1][i + l]);
				}
				dp[i][i + l] = val + total[i + l] - total[i - 1];
			}
		}
		cout << dp[1][K] << endl;
	}
}