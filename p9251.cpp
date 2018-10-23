#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	string A, B;
	cin >> A >> B;

	dp[0][0] = A[0] == B[0];

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == B[0]) dp[i][0] = 1;
		else
			dp[i][0] = dp[i - 1][0];
	}
	for (int j = 0; j < B.size(); j++) {
		if (A[0] == B[j]) dp[0][j] = 1;
		else
			dp[0][j] = dp[0][j - 1];
	}

	for (int i = 1; i < A.size(); i++) {
		for (int j = 1; j < B.size(); j++) {
			if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[A.size() - 1][B.size() - 1] << "\n";
}