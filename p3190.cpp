#include <iostream>
#include <deque>
#include <set>
#include <unordered_map>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define hash unordered_map

int next_dir[4][2] = { {LEFT, RIGHT}, {RIGHT, LEFT}, {DOWN, UP}, {UP, DOWN} };
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int map[101][101];
hash<int, char> command;

bool inBoard(pair<int, int> head, int N) {
	int x = head.first;
	int y = head.second;

	return (x >= 1 && x <= N && y >= 1 && y <= N);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}
	int L;
	cin >> L;
	for (int i = 0; i < L; i++) {
		int time;
		char turn;
		cin >> time >> turn;
		command[time] = turn;
	}

	deque<pair<int, int>> dq;
	dq.push_back({ 1,1 });
	int dir = RIGHT;

	for (int time = 1; ; time++) {
		
		bool crash = false;
		pair<int, int> head = dq.front();
		pair<int, int> next_head = { head.first + d[dir][0], head.second + d[dir][1] };
		if (!inBoard(next_head, N)) {
			crash = true;
		}

		if (!crash) {
			// Move
			dq.push_front(next_head);
			
			set<pair<int, int>> crash_set;
			for (auto it = dq.begin(); it != dq.end(); ++it) {
				if (crash_set.insert(*it).second == false) {
					crash = true;
					break;
				}
			}
			if (map[next_head.first][next_head.second] != 1) {
				dq.pop_back();
			}
			else {
				map[next_head.first][next_head.second] = 0;
			}
		}

		if (crash) {
			printf("%d\n", time);
			break;
		}


		if (command.find(time) != command.end()) {
			if (command[time] == 'L') {
				dir = next_dir[dir][0];
			}
			else if (command[time] == 'D') {
				dir = next_dir[dir][1];
			}
		}
	}

}