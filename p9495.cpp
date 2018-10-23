#include <iostream>
#include <algorithm>
using namespace std;

int p[100001][3];
int dp[100001][3];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i][1];
		}
		for (int i = 1; i <= n; i++) {
			cin >> p[i][2];
		}

		dp[1][0] = 0;
		dp[1][1] = p[1][1];
		dp[1][2] = p[1][2];

		for (int i = 2; i <= n; i++) {
			dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + p[i][1];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + p[i][2];
		}
		cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << endl;
	}

}