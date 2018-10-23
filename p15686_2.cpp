#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int answer = 9999999;

void DFS(int n, int c, vector<int> selected) {
	if (n - c < 0)
		return;
	if (c == 0) {
		int sum = 0;
		for (auto h : house) {
			int min_dist = 9999999;
			for (auto c_idx : selected) {
				min_dist = min(min_dist, abs(h.first - chicken[c_idx - 1].first) + abs(h.second - chicken[c_idx - 1].second));
			}
			sum += min_dist;
		}
		answer = min(answer, sum);
		return;
	}
	selected.push_back(n);
	DFS(n - 1, c - 1, selected);
	selected.pop_back();
	DFS(n - 1, c, selected);
	
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int x; 
			cin >> x;
			if (x == 1) house.push_back(make_pair(i, j));
			else if (x == 2) chicken.push_back(make_pair(i, j));
		}
	}
	vector<int> t;
	DFS(chicken.size(), M, t);
	cout << answer << endl;
}