#include <iostream>
#include <vector>
using namespace std;

int N, M, H;

int bar_list[11][31];


int go_down(int cur, int height) {
	int next_height = -1;
	int next_cur = cur;
	for (int i = height + 1; i <= H; i++) {
		if (bar_list[cur][i] == 1) {
			next_height = i;
			next_cur++;
			break;
		}
		if (bar_list[cur][i] == 2) {
			next_height = i;
			next_cur--;
			break;
		}
	}
	if (next_height == -1) {
		return cur;
	}
	go_down(next_cur, next_height);
	
}

int allSame() {	
	for (int i = 1; i <= N; i++) {
		if (go_down(i, 0) != i)
			return 0;
	}
	return 1;
}

int go(int n, int cnt) {
	if (cnt == n) {
		if (allSame()) return 1;
		else return 0;		
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= H; j++) {
			if (bar_list[i][j] != 0 || bar_list[i + 1][j] != 0) continue;
			bar_list[i][j] = 1;
			bar_list[i + 1][j] = 2;		
			if (go(n, cnt + 1)) return 1;
			bar_list[i][j] = 0;
			bar_list[i + 1][j] = 0;
		}
	}
	return 0;
}

int main() {
	cin >> N >> M >> H;
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		bar_list[b][a] = 1;
		bar_list[b + 1][a] = 2;
	}

	if (go(0, 0))
		cout << 0 << endl;
	else if (go(1, 0))
		cout << 1 << endl;
	else if (go(2, 0))
		cout << 2 << endl;
	else if (go(3, 0))
		cout << 3 << endl;
	else
		cout << -1 << endl;
}