#include <iostream>
#include <algorithm>
using namespace std;

int s[301];
int dp[301];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s[i];
	}
	dp[0] = 0;
	dp[1] = s[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = max(dp[i - 2] + s[i], dp[i - 3] + s[i - 1] + s[i]);
	}
	cout << dp[N] << endl;
}