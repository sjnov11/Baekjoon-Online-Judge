#include <iostream>	
#include <algorithm>
#include <climits>
using namespace std;

char chess[51][51];
char B[8][8] = { { 'B','W', 'B','W', 'B','W', 'B','W'},
				{ 'W','B', 'W','B', 'W','B', 'W','B' },
				{ 'B','W', 'B','W', 'B','W', 'B','W' },
				{ 'W','B', 'W','B', 'W','B', 'W','B' },
				{ 'B','W', 'B','W', 'B','W', 'B','W' },
				{ 'W','B', 'W','B', 'W','B', 'W','B' },
				{ 'B','W', 'B','W', 'B','W', 'B','W' },
				{ 'W','B', 'W','B', 'W','B', 'W','B' } };

char W[8][8] = { { 'W','B', 'W','B', 'W','B', 'W','B' },
				{ 'B','W', 'B','W', 'B','W', 'B','W' },
				{ 'W','B', 'W','B', 'W','B', 'W','B' },
				{ 'B','W', 'B','W', 'B','W', 'B','W' },
				{ 'W','B', 'W','B', 'W','B', 'W','B' },
				{ 'B','W', 'B','W', 'B','W', 'B','W' },
				{ 'W','B', 'W','B', 'W','B', 'W','B' },
				{ 'B','W', 'B','W', 'B','W', 'B','W' } };

int cost(int r, int c) {
	int cost_b = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[r+i][c+j] != B[i][j]) cost_b++;
		}
	}
	int cost_w = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[r+i][c+j] != W[i][j]) cost_w++;
		}
	}
	return min(cost_w, cost_b);
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> chess[i];
	}

	int answer = INT_MAX;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			answer = min(answer, cost(i, j));
		}
	}
	cout << answer << "\n";
}