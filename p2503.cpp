#include <iostream>
#include <cstring>
using namespace std;

pair<int, int> query(int n, int q) {
	int strike = 0, ball = 0;
	for (int i = 0; i < 3; i++) {
		int q_end = q % 10;
		int temp_n = n;
		for (int j = 0; j < 3; j++) {
			int n_end = temp_n % 10;
			if (q_end == n_end) {
				if (i == j) strike++;
				else ball++;
			}
			temp_n /= 10;
		}
		q /= 10;
	}
	return{ strike,ball };
}

int main() {
	int N; 
	cin >> N;

	int Q[101][3];
	for (int i = 0; i < N; i++) {
		cin >> Q[i][0] >> Q[i][1] >> Q[i][2];
	}

	int cnt = 0;
	for (int num = 123; num <= 999; num++) {
		int check[10]; 
		memset(check, 0, sizeof(int) * 10);
		bool dup = false;
		check[num % 10]++; check[(num / 10) % 10]++; check[(num / 100) % 10]++;
		if (check[0] > 0) continue;
		for (int i = 1; i < 10; i++) {
			if (check[i] > 1) dup = true;
		}
		if (dup) continue;
		bool flag = true;
		for (int i = 0; i < N; i++) {
			auto result = query(num, Q[i][0]);
			if (result.first != Q[i][1] || result.second != Q[i][2]) {
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
	}
	cout << cnt << endl;
}