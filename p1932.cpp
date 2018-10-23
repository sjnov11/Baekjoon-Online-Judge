#include <iostream>
#include <algorithm>
using namespace std;

int p[500][500];
int dp[500][500];


int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> p[i][j];
		}
	}
	dp[0][0] = p[0][0];
	for (int height = 1; height <= N; height++) {
		for (int idx = 0; idx <= height; idx++) {
			int left = 0, right = 0;
			left = idx - 1 >= 0 ? dp[height - 1][idx - 1] : 0;
			right = idx <= height - 1 ? dp[height - 1][idx] : 0;

			dp[height][idx] = max(left, right) + p[height][idx];
		}
	}
	int Answer = 0;
	for (int i = 0; i < N; i++) {
		Answer = max(Answer, dp[N-1][i]);
	}

	cout << Answer << endl;
}


/*
다음 단계로 넘어가는 모든 과정 중
dp[height][index] 모든 index 중 가장 최대인 것을 구한다.
dp[height][index] = max (dp[height-1][index-1], dp[height -1][index]) + p[he][idx]
index 주의하자
*/