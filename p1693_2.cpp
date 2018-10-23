#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

vector<int> adj_list[100001];
int dp[100001][18];


void solve(int prev, int cur) {
	dp[cur][0] = INT_MAX;
	for (int i = 1; i <= 17; i++) {
		dp[cur][i] += i;
	}
	for (int next : adj_list[cur]) {
		if (next == prev) continue;
		solve(cur, next);
		int small_c1 = 0, small_c2 = 0;
		for (int i = 1; i <= 17; i++) {
			if (dp[next][small_c2] > dp[next][i])
				small_c2 = i;
			if (dp[next][small_c1] > dp[next][small_c2])
				swap(small_c1, small_c2);
		}
		for (int i = 1; i <= 17; i++) {
			dp[cur][i] += dp[next][i != small_c1 ? small_c1 : small_c2];
			
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	
	solve(0, 1);
	int ans = INT_MAX;

	for (int i = 1; i <= 17; i++) {
		ans = min(ans, dp[1][i]);
	}
	cout << ans << '\n';
}