	#include <iostream>
	#include <vector>
	using namespace std;

	int board[101][101];

	bool onBoard(int x, int y) {
		return x >= 0 && x <= 100 && y >= 0 && y <= 100;
	}


	void print() {
		for (int i = 0; i <= 7; i++) {
			for (int j = 0; j <= 7; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		printf("=================\n");
	}

	int main() {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int x, y, d, g;
			cin >> x >> y >> d >> g;
			vector<int> dir_list;
			dir_list.push_back(d);
			for (int j = 0; j < g; j++) {
				int end = dir_list.size() - 1;
				for (int k = end; k >= 0; k--) {
					dir_list.push_back((dir_list[k] + 1) % 4);
				}
			}

			board[y][x] = 1;
			//print();
			for (auto dir : dir_list) {
				if (dir == 0) x += 1;
				if (dir == 1) y -= 1;
				if (dir == 2) x -= 1;
				if (dir == 3) y += 1;
				board[y][x] = 1;
				//print();
			}
		
		}
		int answer = 0;
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				if (!onBoard(i + 1, j) || !onBoard(i, j + 1) || !onBoard(i + 1, j + 1)) continue;
				if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] == 1)
					answer += 1;
			}
		}
		cout << answer << endl;
	}