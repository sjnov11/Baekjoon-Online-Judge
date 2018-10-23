#include <iostream>
using namespace std;

int main() {
	int M;
	cin >> M;
	int ball = 1;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		if (x == ball) {
			ball = y;
		}
		else if (y == ball) {
			ball = x;
		}
	}
	cout << ball << "\n";
}