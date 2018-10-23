#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int p[1001];
int dp[1001];
vector<int> order[1001];

int solve(int W) {
	if (dp[W] >= 0) {
		return dp[W];
	}
	int prev_max = 0;
	for (int i = 0; i < order[W].size(); i++) {
		int prev = order[W][i];
		if (dp[prev] < 0)
			solve(prev);
		prev_max = max(prev_max, dp[prev]);
	}
	dp[W] = prev_max + p[W];
	return dp[W];
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {

		int N, K;
		cin >> N >> K;

		for (int i = 1; i <= N; i++) {
			dp[i] = -1;
			order[i].clear();
		}

		for (int i = 1; i <= N; i++) {
			cin >> p[i];
		}
		for (int i = 0; i < K; i++) {
			int prev, next;
			cin >> prev >> next;
			order[next].push_back(prev);
		}

		int W;
		cin >> W;
		cout << solve(W) << endl;
		

		
	}

}


/*
	d[W] 는 W를 짓는데 까지 시간.
	2->4 3->4

	선행 건물 시간의 최대 + 자기 시간

	d[4] = max(d[2], d[3]) + p[4];

*/