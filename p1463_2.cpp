#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	int N;
	cin >> N;
	
	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i <= N; i++) {
		int a = 999999999,b = 999999999,c= 999999999;
		if (i % 3 == 0) {
			a = dp[i / 3] + 1;
		}
		if (i % 2 == 0) {
			b = dp[i / 2] + 1;
		}
		c = dp[i - 1] + 1;
		dp[i] = min(min(a, b), c);
	}
	cout << dp[N] << endl;
}