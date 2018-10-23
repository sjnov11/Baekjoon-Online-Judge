#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int N, M;
int board[9][9];
vector<pair<int, int>> cctv_list;
int delta[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int answer = 9999999;
bool onBoard(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

void draw(int x, int y, int cur[][9], int dir) {
	int dx = delta[dir][0];
	int dy = delta[dir][1];
	while (true) {
		x += dx, y += dy;
		if (!onBoard(x, y) || cur[x][y] == 6) break;
		else {
			if (cur[x][y] == 0) cur[x][y] = 9;
		}
	}
}

void drawArea(pair<int,int> cctv, int cctv_dir, int cur[][9]) {
	int type = board[cctv.first][cctv.second];

	if (type == 1) {
		int cx = cctv.first, cy = cctv.second;
		if (cctv_dir == 0) draw(cx, cy, cur, RIGHT);
		if (cctv_dir == 1) draw(cx, cy, cur, DOWN);
		if (cctv_dir == 2) draw(cx, cy, cur, LEFT);
		if (cctv_dir == 3) draw(cx, cy, cur, UP);
	}
	if (type == 2) {
		int cx = cctv.first, cy = cctv.second;
		if (cctv_dir == 0) {
			draw(cx, cy, cur, LEFT);
			draw(cx, cy, cur, RIGHT);
		}
		if (cctv_dir == 1) {
			draw(cx, cy, cur, UP);
			draw(cx, cy, cur, DOWN);
		}		
	}
	if (type == 3) {
		int cx = cctv.first, cy = cctv.second;
		if (cctv_dir == 0) {
			draw(cx, cy, cur, UP);
			draw(cx, cy, cur, RIGHT);
		}
		if (cctv_dir == 1) {
			draw(cx, cy, cur, RIGHT);
			draw(cx, cy, cur, DOWN);
		}
		if (cctv_dir == 2) {
			draw(cx, cy, cur, DOWN);
			draw(cx, cy, cur, LEFT);
		}
		if (cctv_dir == 3) {
			draw(cx, cy, cur, LEFT);
			draw(cx, cy, cur, UP);
		}
	}
	if (type == 4) {
		int cx = cctv.first, cy = cctv.second;
		if (cctv_dir == 0) {
			draw(cx, cy, cur, UP);
			draw(cx, cy, cur, LEFT);
			draw(cx, cy, cur, RIGHT);
		}
		if (cctv_dir == 1) {
			draw(cx, cy, cur, RIGHT);
			draw(cx, cy, cur, UP);
			draw(cx, cy, cur, DOWN);
		}
		if (cctv_dir == 2) {
			draw(cx, cy, cur, DOWN);
			draw(cx, cy, cur, LEFT);
			draw(cx, cy, cur, RIGHT);
		}
		if (cctv_dir == 3) {
			draw(cx, cy, cur, LEFT);
			draw(cx, cy, cur, UP);
			draw(cx, cy, cur, DOWN);
		}
	}
	if (type == 5) {
		int cx = cctv.first, cy = cctv.second;
		draw(cx, cy, cur, UP);
		draw(cx, cy, cur, LEFT);
		draw(cx, cy, cur, RIGHT);
		draw(cx, cy, cur, DOWN);		
	}
	


}

void setBoard(int a[][9], int b[][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

int getResult(int a[][9]) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 0) result++;
		}
	}
	return result;
}

void go(int cur, int cur_board[][9]) {
	if (cur == cctv_list.size()) {
		answer = min(answer, getResult(cur_board));
		return;
	}

	int temp[9][9];	
	pair<int, int> cctv = cctv_list[cur];
	int type = cur_board[cctv.first][cctv.second];
	for (int d = 0; d < 4; d++){
		if (d == 2 && type == 2) break;
		setBoard(temp, cur_board);		
		drawArea(cctv, d, temp);
		go(cur + 1, temp);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5)
				cctv_list.push_back({ i,j });
		}
	}

	go(0, board);
	cout << answer << endl;
}