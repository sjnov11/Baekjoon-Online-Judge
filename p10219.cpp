#include <iostream>
using namespace std;

char meat[11][11];
char answer[11][11];
int main() {
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int H, W;
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			cin >> meat[i];
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
				answer[i][j] = meat[H - i - 1][j];
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << answer[i][j];
			}
			cout << "\n";
		}

	}
	

}