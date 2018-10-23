#include <iostream>
using namespace std;

int N, M, H;

int ladder[11][31];

int go2(int hor, int ver) {
	if (ver > H) return hor;
	if (ladder[hor][ver] == 1)
		hor += 1;
	else if (hor - 1 >= 1 && ladder[hor - 1][ver] == 1) 
		hor -= 1;
	
	ver += 1;
	return go2(hor, ver);
}

bool go(int hor, int ver) {
	int start_hor = hor;
	for (int i = ver; i <= H; i++) {
		if (ladder[hor][i] == 1)
			hor += 1;
		else if (hor - 1 >= 1 && ladder[hor - 1][i] == 1)
			hor -= 1;
	}
	if (start_hor == hor) return true;
	return false;
}

bool putLadder(int cur, int put_cnt, int li, int lj) {
	if (cur == put_cnt) {		
		for (int i = 1; i <= N; i++) {
			if (!go(i, 1)) return false;
		}
		return true;
	}
	for (int i = li; i < N; i++) {
		for (int j = i == li? lj + 1 : 0; j <= H; j++) {
			
			if (ladder[i][j] == 1) continue;
			if (i - 1 >= 1 && ladder[i - 1][j] == 1) continue;
			if (i + 1 < N && ladder[i + 1][j] == 1) continue;
			ladder[i][j] = 1;
			
			if (putLadder(cur + 1, put_cnt, i, j)) 
				return true;
			ladder[i][j] = 0;
		}
	}
	return false;
}

int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[b][a] = 1;
	}

	for (int i = 0; i <= 3; i++) {
		if (putLadder(0, i, 1, 1)) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
	

}