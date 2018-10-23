#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int box[1001][1001];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int main() {
	ios::sync_with_stdio(false);
	int M, N;
	cin >> M >> N;

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	int Answer = 0;

	while (true) {
		vector<pair<int, int>> well_list;
		while (!q.empty()) {
			well_list.push_back(q.front());
			q.pop();
		}
		for (int i = 0; i < well_list.size(); i++) {
			pair<int, int> cur;
			cur = well_list[i];
			int px, py;

			for (int d = 0; d < 4; d++) {
				px = cur.first + dir[d][0];
				py = cur.second + dir[d][1];
				//cout << "(" << px << ", " << py << ")" << endl;
				if (px >= 0 && px < N && py >= 0 && py < M) {
					if (box[px][py] == 0) {
						box[px][py] = 1;
						q.push(make_pair(px, py));
					}
				}
			}

		}
		if (q.empty())
			break;
		Answer++;	
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
				
		}
	}
	cout << Answer << '\n';
}