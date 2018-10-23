#include <iostream>
using namespace std;

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

int dice[6];
int map[21][21];
int N, M, x, y, K;

bool inBoard(pair<int, int> pos) {
	int x = pos.first;
	int y = pos.second;
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void moveUp() {
	int temp[6];
	for (int i = 0; i < 6; i++) {
		temp[i] = dice[i];
	}
	dice[0] = temp[4];
	dice[1] = temp[0];
	dice[4] = temp[5];
	dice[5] = temp[1];
}
void moveDown() {
	int temp[6];
	for (int i = 0; i < 6; i++) {
		temp[i] = dice[i];
	}
	dice[0] = temp[1];
	dice[1] = temp[5];
	dice[4] = temp[0];
	dice[5] = temp[4];
}
void moveLeft() {
	int temp[6];
	for (int i = 0; i < 6; i++) {
		temp[i] = dice[i];
	}
	dice[0] = temp[2];
	dice[2] = temp[5];
	dice[3] = temp[0];
	dice[5] = temp[3];
}
void moveRight() {
	int temp[6];
	for (int i = 0; i < 6; i++) {
		temp[i] = dice[i];
	}
	dice[0] = temp[3];
	dice[2] = temp[0];
	dice[3] = temp[5];
	dice[5] = temp[2];
}
void action(int dir, pair<int, int> &pos) {	
	if (dir == UP) {		
		pos.first--;
		if (!inBoard(pos)) {
			pos.first++;
			return;
		}
		moveUp();
	}
	else if (dir == DOWN) {		
		pos.first++;
		if (!inBoard(pos)) {
			pos.first--;
			return;
		}
		moveDown();
	}
	else if (dir == LEFT) {		
		pos.second--;
		if (!inBoard(pos)) {
			pos.second++;
			return;
		}
		moveLeft();
	}
	else if (dir == RIGHT) {		
		pos.second++;
		if (!inBoard(pos)) {
			pos.second--;
			return;
		}
		moveRight();
	}

	if (map[pos.first][pos.second] == 0) {
		map[pos.first][pos.second] = dice[5];
	}
	else {
		dice[5] = map[pos.first][pos.second];
		map[pos.first][pos.second] = 0;
	}
	printf("%d\n", dice[0]);
}

int main() {
	pair<int, int> pos;
	
	//cin >> N >> M >> x >> y >> K;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	pos = { x, y };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d",&map[i][j]);
		}
	}
	for (int i = 0; i < K; i++) {
		int k;
		scanf("%d", &k);
		action(k, pos);
	}
}