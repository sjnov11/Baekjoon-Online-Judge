#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[25][25];
bool visited[25][25];
vector<int> answer;
int cnt;

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;
	// Up
	if (x - 1 >= 0 && !visited[x - 1][y] && map[x - 1][y] == 1) {
		dfs(x - 1, y);
	}
	// Down
	if (x + 1 < N && !visited[x + 1][y] && map[x + 1][y] == 1) {
		dfs(x + 1, y);
	}
	// Left
	if (y - 1 >= 0 && !visited[x][y - 1] && map[x][y - 1] == 1) {
		dfs(x, y - 1);
	}
	// Right
	if (y + 1 < N && !visited[x][y + 1] && map[x][y + 1] == 1) {
		dfs(x, y + 1);
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 0;

			if (!visited[i][j] && map[i][j] == 1) {
				dfs(i, j);
			}
			if (cnt >0)
				answer.push_back(cnt);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}