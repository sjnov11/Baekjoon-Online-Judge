#include <iostream>
using namespace std;

int A[100001];
int dp[100001];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	dp[1] = A[1];
	for (int i = 2; i <= N; i++) {
		if (dp[i - 1] < 0)
			dp[i] = A[i];
		else
			dp[i] = dp[i - 1] + A[i];
	}

	int answer = dp[1];
	for (int i = 2; i <= N; i++) {
		if (answer < dp[i])
			answer = dp[i];
	}
	cout << answer << endl;
}