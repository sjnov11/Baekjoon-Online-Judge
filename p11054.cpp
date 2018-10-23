#include <iostream>
using namespace std;

int A[1001];
int dp1[1001];
int dp2[1001];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	dp1[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) {
				if (dp1[i] < dp1[j]) {
					dp1[i] = dp1[j];
				}
			}
		}
		dp1[i]++;
	}

	dp2[N] = 1;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N; j > i; j--) {
			if (A[i] > A[j]) {
				if (dp2[i] < dp2[j]) {
					dp2[i] = dp2[j];
				}
			}
		}
		dp2[i]++;
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (dp1[i] + dp2[i] > answer) {
			answer = dp1[i] + dp2[i] - 1;
		}
	}
	cout << answer << "\n";
}