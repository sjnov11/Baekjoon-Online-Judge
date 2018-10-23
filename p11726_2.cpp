#include <iostream>
using namespace std;

int dp[1001];

int go(int n) {
	if (dp[n] != 0)
		return dp[n];
	return dp[n] = (go(n - 1) + go(n - 2)) % 10007;
}


int main() {
	int N;
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	cout << go(N) << endl;

	
}