#include <iostream>
using namespace std;
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int N, M;
int map[51][51];
int r, c, d;

bool onBoard(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

int turnLeft(int dir) {
	int result = dir - 1;
	if (result < 0) result += 4;
	return result;
}

bool canMoveFront(int x, int y, int dir) {
	if (dir == NORTH && map[x - 1][y] == 0) return true;
	if (dir == EAST && map[x][y + 1] == 0) return true;
	if (dir == SOUTH && map[x + 1][y] == 0) return true;
	if (dir == WEST && map[x][y - 1] == 0) return true;
	return false;
}

bool canMoveBack(int x, int y, int dir) {
	if (dir == NORTH && map[x + 1][y] != 1) return true;
	if (dir == EAST && map[x][y - 1] != 1) return true;
	if (dir == SOUTH && map[x - 1][y] != 1) return true;
	if (dir == WEST && map[x][y + 1] != 1) return true;
	return false;
}

void moveFront(int &x, int &y, int dir) {
	if (dir == NORTH) x -= 1;
	if (dir == EAST) y += 1;
	if (dir == SOUTH) x += 1;
	if (dir == WEST) y -= 1;
}

void moveBack(int &x, int &y, int dir) {
	if (dir == NORTH) x += 1;
	if (dir == EAST) y -= 1;
	if (dir == SOUTH) x -= 1;
	if (dir == WEST) y += 1;
}

void go() {
	while (true) {
		int turn;
		for (turn = 0; turn < 4; turn++) {
			d = turnLeft(d);
			if (canMoveFront(r, c, d)) {
				moveFront(r, c, d);
				map[r][c] = 2;
				break;
			}
		}
		if (turn == 4) {
			//d = turnLeft(d);
			if (canMoveBack(r, c, d)) moveBack(r, c, d);
			else break;
		}		
	}
}

int main() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	map[r][c] = 2;
	go();

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) answer++;
		}
	}
	cout << answer << endl;
}