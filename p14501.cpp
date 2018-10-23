#include <iostream>
#include <algorithm>
using namespace std;
int N;
int T[16];
int P[16];
int dp[16];

//int go(int start, int sum) {
//	if (dp[start] >= 0) return dp[start];
//	int result = sum;
//	for (int i = start; i <= N; i++) {
//		if (N - i + 1 >= T[i]) {			
//			result = max(result, go(i + T[i], sum + P[i]));
//		}
//	}
//	dp[start] = result;
//	return result;
//}

int go(int cur) {
	int result = 0;
	if (cur == N + 1) return 0;
	if (cur > N + 1) return -99999999;
	result = max(result, go(cur + 1));
	result = max(result, go(cur + T[cur]) + P[cur]);
	return result;
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = 0; i < 16; i++) {
		dp[i] = -1;
	}
	//cout << go(1, 0) << endl;
	cout << go(1) << endl;
}