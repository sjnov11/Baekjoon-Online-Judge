#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

vector<int> adj_list[100001];
int cache[100001][18];

void solve(int cur, int color, int parent) {
	if (cache[cur][color] > 0)
		return;

	if (adj_list[cur].size() == 1 && adj_list[cur][0] == parent) {
		cache[cur][color] = color;
		return;
	}
	

	for (int next : adj_list[cur]) {
		if (next == parent) continue;
		for (int c1 = 1; c1 < 18; c1++) {
			if (c1 == color) continue;
			solve(next, c1, cur);
		}
	}
	
	for (int next : adj_list[cur]) {
		if (next == parent) continue;
		int next_min_cost = INT_MAX;
		for (int c1 = 1; c1 < 18; c1++) {
			if (c1 == color) continue;
			next_min_cost = min(next_min_cost, cache[next][c1]);
		}
		cache[cur][color] += next_min_cost;
	}
	cache[cur][color] += color;
	return;
}


int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;	

	for (int i = 0; i < n - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		adj_list[n1].push_back(n2);
		adj_list[n2].push_back(n1);
	}

	for (int i = 1; i < 18; i++) {
		solve(1, i, 0);
	}

	int min_cost = INT_MAX;
	for (int i = 1; i < 18; i++) {
		min_cost = min(min_cost, cache[1][i]);
	}
	
	cout << min_cost << endl;
}