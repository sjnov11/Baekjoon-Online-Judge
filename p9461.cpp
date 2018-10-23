#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		long long answer[6];
		answer[1] = 1;
		answer[2] = 1;
		answer[3] = 1;
		answer[4] = 2;
		answer[5] = 2;

		if (N <= 5) {
			cout << answer[N] << endl;
		}
		else {
			for (int i = 6; i <= N; i++) {
				long long cur;
				cur = answer[5] + answer[1];
				for (int j = 1; j <= 4; j++) {
					answer[j] = answer[j + 1];
				}
				answer[5] = cur;
			}
			cout << answer[5] << endl;
		}
	}
	
}