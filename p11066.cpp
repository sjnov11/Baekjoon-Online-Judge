#include <iostream>
#include <map>
#include <algorithm>
#include <limits.h>
using namespace std;

int dp[501][501];
int sum[501];


//int solve(int i, int j) {
//	//cout << "solve(" << i << ", " << j << ")" << endl;
//	if (dp[i][j] >= 0)
//		return dp[i][j];
//	int Answer = 99999999;
//	for (int k = i; k < j; k++) {
//		Answer = min(Answer, solve(i, k) + solve(k + 1, j));
//	}
//	for (int k = i; k <= j; k++) {
//		Answer += cost[k];
//	}
//	dp[i][j] = Answer;
//	return dp[i][j];
//}


int main() {
	int T;
	cin >> T;

	
	for (int tc = 1; tc <= T; tc++) {

		int K;
		cin >> K;

		for (int i = 1; i <= K; i++) {
			for (int j = 1; j <= K; j++) {
				dp[i][j] = -1;				
			}			
		}

		for (int i = 1; i <= K; i++) {
			int cost;
			cin >> cost;
			sum[i] = sum[i - 1] + cost;
		}

		// 하위 구간의 dp가 다 구해져야 다음 구간을 구할 수 있다. 그 구간 i
		// i = 0 [1][1] [2][2] ... 필요없네 0 이니간
		// i = 1 [1][2] [2][3] ...
		// i = 2 [1][3] [2][4] ...
		for (int i = 0; i < K; i++) {
			for (int front = 1; front + i <= K; front++) {
				int end = front + i;
				if (i == 0) {
					dp[front][end] = 0;
					continue;
				}
				else
					dp[front][end] = INT_MAX;
				// [front][end] 를 구하자
				// 2개로 나누어 두 dp의 합 중 최소가 답
				for (int mid = front; mid < end; mid++) {
					dp[front][end] = min(dp[front][end], dp[front][mid] + dp[mid + 1][end]);
				}
				// front-mid 와 mid+1-end를 합치는데 드는 비용을 더한다.
				dp[front][end] += (sum[end] - sum[front - 1]);
			}
		}
		
		cout << dp[1][K] << endl;
	}
}