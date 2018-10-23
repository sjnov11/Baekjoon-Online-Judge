#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int S[21][21];
int A[21];
int answer = 99999999;

void go(int idx, int cnt) {	
	if (cnt == N / 2) {
		int A_score = 0;
		int B_score = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i] == 1 && A[j] == 1) A_score += S[i][j];
				if (A[i] == 0 && A[j] == 0) B_score += S[i][j];
			}
		}
		answer = min(answer, abs(A_score - B_score));
		return;
	}
	if (idx == N) return;

	go(idx + 1, cnt);
	A[idx] = 1;
	go(idx + 1, cnt + 1);
	A[idx] = 0;
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}
	go(0, 0);
	cout << answer << endl;
}