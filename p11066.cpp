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

		// ���� ������ dp�� �� �������� ���� ������ ���� �� �ִ�. �� ���� i
		// i = 0 [1][1] [2][2] ... �ʿ���� 0 �̴ϰ�
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
				// [front][end] �� ������
				// 2���� ������ �� dp�� �� �� �ּҰ� ��
				for (int mid = front; mid < end; mid++) {
					dp[front][end] = min(dp[front][end], dp[front][mid] + dp[mid + 1][end]);
				}
				// front-mid �� mid+1-end�� ��ġ�µ� ��� ����� ���Ѵ�.
				dp[front][end] += (sum[end] - sum[front - 1]);
			}
		}
		
		cout << dp[1][K] << endl;
	}
}