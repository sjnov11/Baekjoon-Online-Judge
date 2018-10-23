#include <iostream>
using namespace std;

int N, M;
int map[501][501];
int dp[501][501];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int onRange(int x, int y) {
	if (x <= 0 || x > M || y <= 0 || y > N)
		return 0;
	return 1;
}

int go(int x, int y) {
	if (dp[x][y] > 0)
		return dp[x][y];
	if (dp[x][y] == -1)
		return 0;
	if (x == M && y == N)
		return dp[x][y] = 1;
	
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (onRange(nx, ny) && map[x][y] > map[nx][ny]) {
			dp[x][y] += go(nx, ny);
		}		
	}
	if (dp[x][y] == 0) {
		dp[x][y] = -1;
		return 0;
	}
	return dp[x][y];
}


int main() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	go(1, 1);
	cout << (dp[1][1] == -1 ? 0 : dp[1][1]) << "\n";
	
	//for (int i = 1; i <= M; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}