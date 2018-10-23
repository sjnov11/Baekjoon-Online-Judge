#include <iostream>
using namespace std;

int num[2001];
int dp[2001][2001];

int go(int s, int e) {
	if (dp[s][e] >= 0) return dp[s][e];
	if (s == e) return dp[s][e] = 1;
	if (num[s] != num[e]) return dp[s][e] = 0;
	if (s + 1 >= e - 1) return dp[s][e] = 1;
	return dp[s][e] = go(s + 1, e - 1);
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = -1;
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		cout << go(S, E) << "\n";
	}
}