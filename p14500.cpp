#include <iostream>
#include <algorithm>
using namespace std;

int board[501][501];
int visited[501][501];
int N, M;

bool inBoard(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M)
		return true;
	return false;
}

int go(int x, int y, int cnt, int sum) {
	if (cnt == 4) return sum;
	if (!inBoard(x, y)) return -99999999;
	if (visited[x][y]) return -99999999;

	visited[x][y] = true;
	int result = -1;
	// up
	result = max(result, go(x - 1, y, cnt + 1, sum + board[x][y]));
	// down
	result = max(result ,go(x + 1, y, cnt + 1, sum + board[x][y]));
	// left
	result = max(result, go(x, y - 1, cnt + 1, sum + board[x][y]));
	// right
	result = max(result, go(x, y + 1, cnt + 1, sum + board[x][y]));

	visited[x][y] = false;
	return result;
}

int caseFuck(int x, int y) {
	int answer = 0;
	// で
	if (inBoard(x + 1, y - 1) && inBoard(x + 1, y) && inBoard(x + 1, y + 1))
		answer = max(answer, board[x][y] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]);
	// た
	if (inBoard(x + 1, y) && inBoard(x + 1, y + 1) && inBoard(x + 2, y))
		answer = max(answer, board[x][y] + board[x + 1][y] + board[x + 1][y + 1] + board[x + 2][y]);
	// ぬ
	if (inBoard(x, y + 1) && inBoard(x, y + 2) && inBoard(x + 1, y + 1))
		answer = max(answer, board[x][y] + board[x][y + 1] + board[x][y + 2] + board[x + 1][y + 1]);
	// っ
	if (inBoard(x + 1, y) && inBoard(x + 1, y - 1) && inBoard(x + 2, y))
		answer = max(answer, board[x][y] + board[x + 1][y] + board[x + 1][y - 1] + board[x + 2][y]);
	return answer;
}


int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	caseFuck(0, 1);
	int answer = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			answer = max(answer, go(i, j, 0, 0));
			answer = max(answer, caseFuck(i, j));
		}
	}
	cout << answer << endl;

}