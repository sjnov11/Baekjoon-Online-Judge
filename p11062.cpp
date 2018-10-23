#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int card[1001];
int dp[1001][1001];

int go(int i, int j, int p) {
	if (dp[i][j] > 0) return dp[i][j];
	
	if (p == 0) {
		if (i == j) return dp[i][j] = card[i];
		return dp[i][j] = max(go(i + 1, j, p ^ 1) + card[i],
			go(i, j - 1, p ^ 1) + card[j]);
	}
	else {
		if (i == j) return dp[i][j] = 0;
		return dp[i][j] = min(go(i + 1, j, p ^ 1), 
			go(i, j - 1, p ^ 1));
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		memset(dp, 0, sizeof(int) * 1001 * 1001);
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> card[i];
		}
		cout << go(1, N, 0) << endl;
	}
}