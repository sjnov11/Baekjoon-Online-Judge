#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[9][9];
vector<pair<int, int>> viruses;
int answer = 0;

bool canMove(int x, int y, int cur[][9]) {
	return x >= 0 && x < N && y >= 0 && y < M && cur[x][y] == 0;
}

void spreadVirus(int x, int y, int cur[][9]) {
	cur[x][y] = 2;
	// Up
	if (canMove(x - 1, y, cur)) spreadVirus(x - 1, y, cur);
	if (canMove(x + 1, y, cur)) spreadVirus(x + 1, y, cur);
	if (canMove(x, y - 1, cur)) spreadVirus(x, y - 1, cur);
	if (canMove(x, y + 1, cur)) spreadVirus(x, y + 1, cur);
}

void spreadViruses() {	
	int temp[9][9];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = map[i][j];
		}
	}

	for (auto virus : viruses) {
		spreadVirus(virus.first, virus.second, temp);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) cnt++;
		}
	}
	answer = max(answer, cnt);
}

void buildWall(int cnt) {	
	if (cnt == 3) {
		spreadViruses();
		return;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) continue;
			map[i][j] = 1;
			buildWall(cnt + 1);
			map[i][j] = 0;
		}
	}
	return;
}


int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) viruses.push_back({ i,j });
		}
	}

	buildWall(0);
	cout << answer << endl;

}