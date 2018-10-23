#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> comb_list;

void comb(int n, int c, vector<int> result) {	
	if (c == 0) {
		comb_list.push_back(result);
		return;
	}
	if (n == 0)
		return;

	comb(n - 1, c, result);
	result.push_back(n);
	comb(n - 1, c - 1, result);
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> chicken;
	vector<pair<int, int>> house;

	vector<int> t;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (x == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	comb(chicken.size(), M, t);
	
	int answer = 999999;
	for (int i = 0; i < comb_list.size(); i++) {
		int sum = 0;
		for (auto h : house) {
			int min_dist = 999999;
			for (auto c : comb_list[i]) {
				min_dist = min(min_dist, abs(h.first - chicken[c - 1].first) + abs(h.second - chicken[c - 1].second));
			}
			sum += min_dist;
		}
		answer = min(answer, sum);
	}

	cout << answer << endl;
}