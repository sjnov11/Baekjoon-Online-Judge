#include <iostream>
#include <string>
using namespace std;

int dp[2501];
int pal[2501][2501];
string S;

int isPal(int s, int e) {
	if (pal[s][e] >= 0) return pal[s][e];
	if (s == e) return pal[s][e] = 1;
	if (s > e) return 1;
	if (S[s - 1] != S[e - 1]) return pal[s][e] = 0;
	return pal[s][e] = isPal(s + 1, e - 1);
}


int main() {
	cin >> S;
	
	
	for (int i = 1; i <= S.size(); i++) {
		dp[i] = 99999999;
	}
	for (int i = 1; i <= S.size(); i++) {
		for (int j = 1; j <= S.size(); j++) {
			pal[i][j] = -1;
		}
	}
	
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= S.size(); i++) {		
		for (int j = 1; j < i; j++) {
			if (isPal(j, i)) {
				if (dp[i] > dp[j - 1] + 1) {
					dp[i] = dp[j - 1] + 1;
				}
			}
		}
		if (dp[i] > dp[i - 1] + 1) {
			dp[i] = dp[i - 1] + 1;
		}
	}
	cout << dp[S.size()] << "\n";
}