#include <iostream>
using namespace std;

int dp[31];


int main() {
	int N;
	cin >> N;
	dp[0] = 1;
	for (int i = 2; i <= N; i+=2) {
		dp[i] += 3 * dp[i - 2];
		for (int j = 4; j <= i; j += 2) {
			dp[i] += 2 * dp[i - j];
		}
	}

	cout << dp[N] << endl;
}