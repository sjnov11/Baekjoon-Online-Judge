#include <iostream>
using namespace std;

int A[2001];
int cache[2001][2001];

int dp(int s, int e) {
	if (cache[s][e] >= 0) return cache[s][e];
	if (s == e) return cache[s][e] = 1;
	if (s > e) return 1;
	if (A[s] != A[e]) return cache[s][e] = 0;
	return cache[s][e] = dp(s + 1, e - 1);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cache[i][j] = -1;
		}
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		cout << dp(S, E) << "\n";
	}

}