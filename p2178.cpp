#include <iostream>
#include <limits.h> 
#include <algorithm>
#include <queue>
using namespace std;

int map[100][100];
bool visited[100][100];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int N, M;
int Answer = INT_MAX;



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		char* line = new char[M];
		cin >> line;
		for (int j = 0; j < M; j++) {
			map[i][j] = line[j] - '0';
		}
	}

	
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	int Answer = 0;
	bool find = false;
	while (!find) {
		vector<pair<int, int>> pos_list;
		while (!q.empty()) {
			pos_list.push_back(q.front());
			q.pop();
		}
		Answer++;
		
		for (int i = 0; i < pos_list.size(); i++) {
			if (pos_list[i].first == N - 1 && pos_list[i].second == M - 1) {
				find = true;
				break;
			}

			int nx, ny;

			for (int j = 0; j < 4; j++) {
				nx = pos_list[i].first + dir[j][0];
				ny = pos_list[i].second + dir[j][1];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (map[nx][ny] == 1 && !visited[nx][ny]) {
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
					}
				}
			}
		}

	}
	cout << Answer << '\n';
}