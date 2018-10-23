#include <iostream>
using namespace std;

int A[21];
int answer = 0;
int N, S;
int go(int cur, int sum) {
	if (cur == N) {
		if (sum == S) answer++;
		return 0;
	}
	go(cur + 1, sum + A[cur]);
	go(cur + 1, sum);
	return 0;
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	go(0, 0);
	if (S == 0) answer--;
	cout << answer << endl;
}