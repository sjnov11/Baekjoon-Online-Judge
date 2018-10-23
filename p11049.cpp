#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

pair<int, int> matrix[501];
int dp[501][501];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		matrix[i] = { a, b };
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = INT_MAX;
		}
	}

	for (int i = 1; i <= N; i++) {
		dp[i][i] = 0;
	}
	
	for (int l = 1; l <= N - 1; l++) {
		for (int i = 1; i <= N - l; i++) {
			for (int k = i; k <= i + l - 1; k++) {
				dp[i][i+l] = min(dp[i][i+l], dp[i][k] + dp[k + 1][i + l] 
					+ matrix[i].first * matrix[k].second * matrix[i+l].second);
			}
		}
	}
	cout << dp[1][N] << endl;
}