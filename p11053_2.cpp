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

	
	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		int max_len = 0;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				max_len = max(max_len, dp[j]);
			}
		}
		dp[i] = max_len + 1;
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";
}