#include <iostream>
#include <algorithm>
using namespace std;

int w[10001];
int dp[10001][3];


int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	dp[1][0] = 0;
	dp[1][1] = w[1];
	dp[1][2] = w[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + w[i];
		dp[i][2] = dp[i - 1][1] + w[i];
	}

	cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << "\n";
}