#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int, int>> dc;
int map[101][101];

int sabun(pair<int, int> a, pair<int, int> b) {
	if (a.first >= b.first && a.second < b.second) {
		return 1;
	}
	if (a.first >= b.first && a.second >= b.second) {
		return 2;
	}
	if (a.first < b.first && a.second >= b.second) {
		return 3;
	}
	else
		return 4;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dc.push_back({ x,y });
		if (d == 0) {
			dc.push_back({ x + 1,y });
		}
		else if (d == 1) {
			dc.push_back({ x, y - 1 });
		}
		else if (d == 2) {
			dc.push_back({ x - 1,y });
		}
		else if (d == 3) {
			dc.push_back({ x, y + 1 });
		}
		for (int gc = 0; gc < g; gc++) {
			auto base = dc[dc.size() - 1];
			int K = dc.size();
			for (int i = K - 2; i >= 0; i--) {
				auto cur = dc[i];
				int s = sabun(cur, base);
				int dx = abs(base.first - cur.first);
				int dy = abs(base.second - cur.second);
				if (s == 1) {
					dc.push_back({ base.first + dy, base.second + dx });
				}
				else if (s == 2) {
					dc.push_back({ base.first - dy, base.second + dx });
				}
				else if (s == 3) {
					dc.push_back({ base.first - dy, base.second - dx });
				}
				else if (s == 4) {
					dc.push_back({ base.first + dy, base.second - dx });
				}
			}
		}
		/*for (auto a : dc) {
			cout << "(" << a.first << ", " << a.second << ")\n";
		}*/
		for (auto a : dc) {
			map[a.first][a.second] = 1;
		}
		dc.clear();
	}
	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				answer++;
		}
	}
	cout << answer << endl;
}