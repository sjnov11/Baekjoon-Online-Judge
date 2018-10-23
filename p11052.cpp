#include <iostream>
using namespace std;

int dp[1001];
int p[1001];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (dp[i] < dp[i - j] + p[j])
				dp[i] = dp[i - j] + p[j];
		}
	}
	cout << dp[N] << endl;
}