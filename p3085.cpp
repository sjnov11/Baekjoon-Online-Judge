#include <iostream>
#include <algorithm>
using namespace std;

char board[51][51];
int adj[4][2] = { {-1, 0}, {1, 0}, {0,-1}, {0,1} };

void swap(char* c1, char* c2) {
	char t = *c2;
	*c2 = *c1;
	*c1 = t;
}

int count(int N) {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int row = 0;
		int cnt = 1;
		char c = board[i][0];
		for (int j = 1; j < N; j++) {
			if (c != board[i][j]) {
				row = max(row, cnt);
				c = board[i][j];
				cnt = 1;
				continue;
			}
			cnt++;
		}
		row = max(row, cnt);
		answer = max(answer, row);
	}

	for (int i = 0; i < N; i++) {
		int col = 0;
		int cnt = 1;
		char c = board[0][i];
		for (int j = 1; j < N; j++) {
			if (c != board[j][i]) {
				col = max(col, cnt);
				c = board[j][i];
				cnt = 1;
				continue;
			}
			cnt++;
		}
		col = max(col, cnt);
		answer = max(answer, col);
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int answer = 0;
	// ±³È¯
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				int dx = adj[k][0];
				int dy = adj[k][1];
				if (i + dx < 0 || i + dx >= N || j + dy < 0 || j + dy >= N)
					continue;
				swap(&board[i][j], &board[i + dx][j + dy]);
				answer = max(answer, count(N));
				swap(&board[i][j], &board[i + dx][j + dy]);
			}
		}
	}
	cout << answer << endl;
}