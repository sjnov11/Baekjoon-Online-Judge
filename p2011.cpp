#include <iostream>
#include <string>
using namespace std;

int n[5001];
int dp[5001];


int main() {
	string s;
	cin >> s;

	int N = s.size();
	
	for (int i = 1; i <= N; i++) {
		n[i] = s[i - 1] - '0';
	}


	dp[0] = 1;
	dp[1] = n[N] == 0 ? 0 : 1;
	
	for (int i = 2; i <= N; i++) {
		if (n[N - i + 1] == 0) {
			dp[i] = 0;
		}
		else if (n[N - i + 1] == 1 || (n[N - i + 1] == 2 && n[N - i + 2] <= 6) ) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
			
		}		
		else {
			dp[i] = dp[i - 1];
		}
	}
	cout << dp[N] << "\n";
}