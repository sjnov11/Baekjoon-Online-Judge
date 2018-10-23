#include <iostream>
using namespace std;

int N, L;
int map[101][101];
bool visited[101][101];

bool onBoard(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

int horizontal() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int cx = i;
		int cy = 0;
		bool possible = true;
		for (int j = 1; j < N; j++) {
			if (abs(map[i][j] - map[cx][cy]) > 1) {
				possible = false; 
				break;
			}
			// Up
			if (map[i][j] == map[cx][cy] + 1) {
				for (int l = 0; l < L; l++) {
					if (!onBoard(cx, cy - l) || map[cx][cy - l] != map[cx][cy] || visited[cx][cy - l]) {
						possible = false;
						break;
					}
				}
				if (possible) {
					for (int l = 0; l < L; l++) {
						visited[cx][cy - l] = true;
					}
				}
				else break;
			}
			else if (map[i][j] == map[cx][cy] - 1) {
				for (int l = 0; l < L; l++) {
					if (!onBoard(i, j + l) || map[i][j + l] != map[i][j] || visited[i][j + l]) {
						possible = false;
						break;
					}
				}
				if (possible) {
					for (int l = 0; l < L; l++) {
						visited[i][j + l] = true;						
					}
				}
				else break;
			}
			cx = i, cy = j;
		}

		if (possible) cnt++;
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
	return cnt;
}

int vertical() {
	int cnt = 0;
	for (int j = 0; j < N; j++) {
		int cx = 0;
		int cy = j;
		bool possible = true;
		for (int i = 1; i < N; i++) {
			if (abs(map[i][j] - map[cx][cy]) > 1) {
				possible = false;
				break;
			}
			// Up
			if (map[i][j] == map[cx][cy] + 1) {
				for (int l = 0; l < L; l++) {
					if (!onBoard(cx - l, cy) || map[cx - l][cy] != map[cx][cy] || visited[cx - l][cy]) {
						possible = false;
						break;
					}
				}
				if (possible) {
					for (int l = 0; l < L; l++) {
						visited[cx - l][cy] = true;
					}
				}
				else break;
			}
			else if (map[i][j] == map[cx][cy] - 1) {
				for (int l = 0; l < L; l++) {
					if (!onBoard(i + l, j) || map[i + l][j] != map[i][j] || visited[i + l][j]) {
						possible = false;
						break;
					}
				}
				if (possible) {
					for (int l = 0; l < L; l++) {
						visited[i + l][j] = true;
					}
				}
				else break;
			}
			cx = i, cy = j;
		}

		if (possible) cnt++;
		for (int i = 0; i < N; i++) {
			visited[i][j] = false;
		}
	}
	return cnt;
}




int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << horizontal() + vertical() << endl;
}