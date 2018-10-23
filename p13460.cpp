#include <iostream>
#include <queue>
using namespace std;
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int N, M;
char map[11][11];


struct Node {
	char m[11][11];
	int time;
};

int rolling(int dir, Node & cur) {
	//char current[11][11];
	
	auto current = cur.m;
	char temp[11][11];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = current[i][j];
		}
	}
	pair<int, int> R_pos;
	pair<int, int> B_pos;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (current[i][j] == 'R') {
				R_pos.first = i;
				R_pos.second = j;
			}
			if (current[i][j] == 'B') {
				B_pos.first = i;
				B_pos.second = j;
			}
		}
	}
	
	if (dir == UP) {
		bool red = false;
		// Rolling Blue 
		while (true) {
			if (current[B_pos.first - 1][B_pos.second] == 'O')
				return -1;
			if (current[B_pos.first - 1][B_pos.second] == '#')
				break;
			if (current[B_pos.first - 1][B_pos.second] == 'R') {
				red = true;
				break;
			}
			else {
				current[B_pos.first][B_pos.second] = '.';
				B_pos.first--;
				current[B_pos.first][B_pos.second] = 'B';
			}
		}
		// Rolling Red 
		while (true) {
			if (current[R_pos.first - 1][R_pos.second] == 'O')
				return 0;
			if (current[R_pos.first - 1][R_pos.second] == '#')
				break;
			if (current[R_pos.first - 1][R_pos.second] == 'B')
				break;
			else {
				current[R_pos.first][R_pos.second] = '.';
				R_pos.first--;
				current[R_pos.first][R_pos.second] = 'R';
			}
		}
		if (red) {
			current[B_pos.first][B_pos.second] = '.';
			B_pos.first = R_pos.first + 1;
			current[B_pos.first][B_pos.second] = 'B';
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] != current[i][j])
					return 1;
			}
		}
		return -1;
	}
	else if (dir == DOWN) {
		bool red = false;
		// Rolling Blue 
		while (true) {
			if (current[B_pos.first + 1][B_pos.second] == 'O')
				return -1;
			if (current[B_pos.first + 1][B_pos.second] == '#')
				break;
			if (current[B_pos.first + 1][B_pos.second] == 'R') {
				red = true;
				break;
			}
			else {
				current[B_pos.first][B_pos.second] = '.';
				B_pos.first++;
				current[B_pos.first][B_pos.second] = 'B';
			}
		}
		// Rolling Red 
		while (true) {
			if (current[R_pos.first + 1][R_pos.second] == 'O')
				return 0;
			if (current[R_pos.first + 1][R_pos.second] == '#')
				break;
			if (current[R_pos.first + 1][R_pos.second] == 'B')
				break;
			else {
				current[R_pos.first][R_pos.second] = '.';
				R_pos.first++;
				current[R_pos.first][R_pos.second] = 'R';
			}
		}
		if (red) {
			current[B_pos.first][B_pos.second] = '.';
			B_pos.first = R_pos.first - 1;
			current[B_pos.first][B_pos.second] = 'B';
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] != current[i][j])
					return 1;
			}
		}
		return -1;
	}

	else if (dir == LEFT) {
		bool red = false;
		// Rolling Blue 
		while (true) {
			if (current[B_pos.first][B_pos.second - 1] == 'O')
				return -1;
			if (current[B_pos.first][B_pos.second - 1] == '#')
				break;
			if (current[B_pos.first][B_pos.second - 1] == 'R') {
				red = true;
				break;
			}
			else {
				current[B_pos.first][B_pos.second] = '.';
				B_pos.second--;
				current[B_pos.first][B_pos.second] = 'B';
			}
		}
		// Rolling Red 
		while (true) {
			if (current[R_pos.first][R_pos.second - 1] == 'O')
				return 0;
			if (current[R_pos.first][R_pos.second - 1] == '#')
				break;
			if (current[R_pos.first][R_pos.second - 1] == 'B')
				break;
			else {
				current[R_pos.first][R_pos.second] = '.';
				R_pos.second--;
				current[R_pos.first][R_pos.second] = 'R';
			}
		}
		if (red) {
			current[B_pos.first][B_pos.second] = '.';
			B_pos.second = R_pos.second + 1;
			current[B_pos.first][B_pos.second] = 'B';
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] != current[i][j])
					return 1;
			}
		}
		return -1;
	}

	else if (dir == RIGHT) {
		bool red = false;
		// Rolling Blue 
		while (true) {
			if (current[B_pos.first][B_pos.second + 1] == 'O')
				return -1;
			if (current[B_pos.first][B_pos.second + 1] == '#')
				break;
			if (current[B_pos.first][B_pos.second + 1] == 'R') {
				red = true;
				break;
			}
			else {
				current[B_pos.first][B_pos.second] = '.';
				B_pos.second++;
				current[B_pos.first][B_pos.second] = 'B';
			}
		}
		// Rolling Red 
		while (true) {
			if (current[R_pos.first][R_pos.second + 1] == 'O')
				return 0;
			if (current[R_pos.first][R_pos.second + 1] == '#')
				break;
			if (current[R_pos.first][R_pos.second + 1] == 'B')
				break;
			else {
				current[R_pos.first][R_pos.second] = '.';
				R_pos.second++;
				current[R_pos.first][R_pos.second] = 'R';
			}
		}
		if (red) {
			current[B_pos.first][B_pos.second] = '.';
			B_pos.second = R_pos.second - 1;
			current[B_pos.first][B_pos.second] = 'B';
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] != current[i][j])
					return 1;
			}
		}
		return -1;
	}
}

void go(int cnt, char current[][11]) {
	char next[11][11];
	
	

	// ╩С
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			next[i][j] = current[i][j];
		}
	}

	// го
	// аб
	// ©Л
}

void test(Node t) {
	t.m[0][1] = 'f';
}
int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	Node init;
	init.time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			init.m[i][j] = map[i][j];
		}
	}
	queue<Node> q;
	q.push(init);
	int answer = -1;
	while (!q.empty()) {
		Node front = q.front();
		q.pop();

		//char cur[11][11];
		for (int i = 0; i < 4; i++) {
			Node next = front;
			int result = rolling(i, next);
			next.time++;
			if (result == 0) {
				int x, y;
				bool blue = false;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (next.m[i][j] == 'B') {
							x = i;
							y = j;
						}
					}
				}
				while (true) {
					if (i == 0) x--;
					if (i == 1) x++;
					if (i == 2) y--;
					if (i == 3) y++;
					if (next.m[x][y] == '#') {
						break;
					}
					else if (next.m[x][y] == 'O') {
						blue = true;
						break;
					}
				}
				if (blue) continue;
				answer = next.time;
				cout << answer << endl;
				return 0;
			}
			else if (result == 1 && next.time < 10) {
				q.push(next);
			}			
		}
	}
	cout << -1 << endl;

}