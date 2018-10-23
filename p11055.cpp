#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int dp[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	dp[1] = A[1];
	int answer = dp[1];
	for (int i = 2; i <= N; i++) {
		int max_sum = 0;
		for (int j = 1; j <= i; j++) {
			if (A[i] < A[j])
				max_sum = max(max_sum, dp[j]);
		}
		dp[i] = max_sum + A[i];
		
		answer = max(answer, dp[i]);
	}

	cout << answer << "\n";

}