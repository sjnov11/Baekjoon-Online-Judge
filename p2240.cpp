#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int dp[1001][31][3];


int main() {
	int T, W;
	cin >> T >> W;
	for (int i = 0; i < T; i++) {
		cin >> A[T - i];
	}
	for (int w = 0; w <= W; w++) {
		dp[1][w][1] = A[1] == 1 ? 1 : 0;
		dp[1][w][2] = A[1] == 2 ? 1 : 0;
	}

	for (int t = 2; t <= T; t++) {
		for (int w = 0; w <= W; w++) {
			for (int p = 1; p <= 2; p++) {
				dp[t][w][p] = dp[t - 1][w][p] + (A[t] == p ? 1 : 0);

				if (w != 0) {
					dp[t][w][p] = max(dp[t][w][p], (dp[t - 1][w - 1][p == 1 ? 2 : 1]) + (A[t] == p ? 1 : 0));
				}
			}
		}
	}
	cout << max(dp[T][W][1], dp[T][W-1][2]) << endl;
}