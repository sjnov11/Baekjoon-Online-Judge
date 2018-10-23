#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

#define IMP -4000000

int A[101];
int sum[101];
int dp[101][51];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int next;
		cin >> next;
		sum[i] = sum[i - 1] + next;
	}

	for (int i = 0; i <= N; i++) {
		for (int j = i; j <= M; j++) {
			dp[i][j] = IMP;	
		}
	}
	dp[0][0] = 0;
	dp[1][1] = sum[1];
	
	
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			for (int k = -1; k <= i - 2; k++) {
				if (k == -1) {
					dp[i][j] = dp[0][j - 1] + sum[i] - sum[k + 1];
					continue;
				}
				dp[i][j] = max(dp[i][j], dp[k][j - 1] + sum[i] - sum[k + 1]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	cout << dp[N][M] << endl;
}