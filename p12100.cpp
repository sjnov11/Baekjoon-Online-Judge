#include <iostream>
using namespace std;
#define UP 0 
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int board[21][21];
int N;
int answer = 0;

void moveUp(int current[21][21]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (current[i][j] != 0) {
				int x = i, y = j;
				while (x - 1 >= 0 && current[x - 1][y] == 0) {
					x--;
				}
				if (x == i && y == j) continue;
				current[x][y] = current[i][j];
				current[i][j] = 0;
			}
		}
	}
}
void moveDown(int current[21][21]) {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (current[i][j] != 0) {
				int x = i, y = j;
				while (x + 1 <= N - 1 && current[x + 1][y] == 0) {
					x++;
				}
				if (x == i && y == j) continue;
				current[x][y] = current[i][j];
				current[i][j] = 0;
			}
		}
	}
}
void moveLeft(int current[21][21]) {
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (current[i][j] != 0) {
				int x = i, y = j;
				while (y - 1 >= 0 && current[x][y - 1] == 0) {
					y--;
				}
				if (x == i && y == j) continue;
				current[x][y] = current[i][j];
				current[i][j] = 0;
			}
		}
	}
}
void moveRight(int current[21][21]) {
	for (int j = N - 1; j >= 0; j--) {
		for (int i = 0; i < N; i++) {
			if (current[i][j] != 0) {
				int x = i, y = j;
				while (y + 1 <= N - 1 && current[x][y + 1] == 0) {
					y++;
				}
				if (x == i && y == j) continue;
				current[x][y] = current[i][j];
				current[i][j] = 0;
			}
		}
	}
}

void concateUp(int current[21][21]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (current[i][j] == 0) continue;
			if (i + 1 < N && current[i][j] == current[i + 1][j]) {
				current[i][j] *= 2;
				current[i + 1][j] = 0;
			}
		}
	}
	moveUp(current);
}
void concateDown(int current[21][21]) {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (current[i][j] == 0) continue;
			if (i - 1 >= 0 && current[i][j] == current[i - 1][j]) {
				current[i][j] *= 2;
				current[i - 1][j] = 0;
			}
		}
	}
	moveDown(current);
}
void concateLeft(int current[21][21]) {
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (current[i][j] == 0) continue;
			if (j + 1 < N && current[i][j] == current[i][j + 1]) {
				current[i][j] *= 2;
				current[i][j + 1] = 0;
			}
		}
	}
	moveLeft(current);
}
void concateRight(int current[21][21]) {
	for (int j = N - 1; j >= 0; j--) {
		for (int i = 0; i < N; i++) {
			if (current[i][j] == 0) continue;
			if (j - 1 >= 0 && current[i][j] == current[i][j - 1]) {
				current[i][j] *= 2;
				current[i][j - 1] = 0;
			}
		}
	}
	moveRight(current);
}
void concate(int dir, int current[21][21]) {
	if (dir == UP) concateUp(current);
	else if (dir == DOWN) concateDown(current);
	else if (dir == LEFT) concateLeft(current);
	else if (dir == RIGHT) concateRight(current);
}
void move(int dir, int current[21][21]) {
	if (dir == UP) moveUp(current);
	else if (dir == DOWN) moveDown(current);
	else if (dir == LEFT) moveLeft(current);
	else if (dir == RIGHT) moveRight(current);
}

void go(int cnt, int current[21][21]) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (current[i][j] > answer)
					answer = current[i][j];
			}
		}
		return;
	}
	int copy[21][21];

	for (int dir = 0; dir < 4; dir++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				copy[i][j] = current[i][j];
			}
		}
		move(dir, copy);
		concate(dir, copy);
		go(cnt + 1, copy);
	}
	
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	//move(RIGHT, board);
	//concate(RIGHT, board);
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << board[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	go(0, board);
	cout << answer << endl;
}