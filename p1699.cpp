#include <iostream>
using namespace std;

int dp[100001];

int main() {
	int N;
	cin >> N;
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = 99999999;
	}
	for (int n = 1; n <= N; n++) {
		for (int i = 1; i * i <= n; i++) {
			if (dp[n] > dp[n - i * i])
				dp[n] = dp[n - i * i] + 1;
		}
	}
	cout << dp[N] << endl;
}