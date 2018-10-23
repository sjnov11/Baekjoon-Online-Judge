#include <iostream>
#include <algorithm>
using namespace std;

#define R 0
#define G 1
#define B 2

int p[1000][3];
int dp[1000][3];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> p[i][j];
		}
	}

	dp[0][R] = p[0][R];
	dp[0][G] = p[0][G];
	dp[0][B] = p[0][B];

	for (int i = 1; i <= N; i++) {
		dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + p[i][R];
		dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + p[i][G];
		dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + p[i][B];
	}
	int Answer = dp[N][R];
	Answer = min(Answer, dp[N][G]);
	Answer = min(Answer, dp[N][B]);

	cout << Answer << endl;
}

/*

i¹øÂ° Ä¥ÇÒ¶§ µé¾ú´Â ÃÑ ºñ¿ë d[i][color]

min d[i][color] = 
d[i][r] = d[i-1][g] °ú d[i-1][b] Áß ÃÖ¼Ú°ª + p[i][r]

*/