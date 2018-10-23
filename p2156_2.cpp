#include <iostream>
#include <algorithm>
using namespace std;

int w[10001];
int dp[10001];

int main() {
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	dp[0] = 0;
	dp[1] = w[1];
	dp[2] = w[1] + w[2];
	//dp[3] = max(max(w[1] + w[2], w[1] + w[3]), w[2] + w[3]);

	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 3] + w[i - 1] + w[i], dp[i - 2] + w[i]), dp[i-1]);
	}
	cout << dp[n] << endl;
}