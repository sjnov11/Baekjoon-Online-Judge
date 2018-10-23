#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int dp[1001][1001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int j = 0; j <= 1000; j++) {
		if (j < A[N]) dp[1][j] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (j < A[N - i + 1])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][A[N - i + 1]] + 1);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][0] << endl;
}