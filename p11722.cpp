#include <iostream>
using namespace std;

int A[1001];
int dp[1001];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (A[i] < A[j]) {
				if (dp[i] < dp[j])
					dp[i] = dp[j];
			}			
		}
		dp[i]++;
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (answer < dp[i])
			answer = dp[i];
	}
	cout << answer << endl;
}