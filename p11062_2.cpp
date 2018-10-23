#include <iostream>
#include <algorithm>
using namespace std;

int card[1001];
int dp[1001][1001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;
		/*for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dp[i][j] = 0;
			}
		}*/
		for (int i = 1; i <= N; i++) {
			cin >> card[i];
		}

		// 0 이면 (명우가 마지막) , 1이면 (근우가 마지막)
		int turn = N % 2;

		for (int k = 0; k < N; k++) {
			for (int i = 1; i <= N - k; i++) {
				int j = i + k;
				/*if (i == j) {
					if (turn == 1)
						dp[i][j] = card[i];
				}*/
				//else {
					if (turn == 1)
						dp[i][j] = max(dp[i + 1][j] + card[i], dp[i][j - 1] + card[j]);
					else
						dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
				//}
			}
			turn = turn ^ 1;
		}
		cout << dp[1][N] << "\n";
	}
}