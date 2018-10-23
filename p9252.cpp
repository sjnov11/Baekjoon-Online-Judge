#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001];
string A, B;
string answer;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> A >> B;
	if (A[0] == B[0]) {
		dp[0][0] = 1;
	}
		

	for (int i = 1; i < A.size(); i++) {
		if (A[i] == B[0]) 
			dp[i][0] = 1;
		else
			dp[i][0] = dp[i - 1][0];
	}

	for (int j = 1; j < B.size(); j++) {
		if (A[0] == B[j]) 
			dp[0][j] = 1;
		else
			dp[0][j] = dp[0][j - 1];
	}

	for (int i = 1; i < A.size(); i++) {
		for (int j = 1; j < B.size(); j++) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int i = A.size() - 1;
	int j = B.size() - 1;
	while (true) {
		if (i < 0 || j < 0) break;
		if (A[i] == B[j]) {
			answer.push_back(A[i]);
			i--, j--;
			continue;
		}
		else {
			if (i - 1 < 0 || j - 1 < 0) {
				if (i - 1 < 0 && j - 1 >= 0) {
					j--;
					continue;
				}
				else if (i - 1 >= 0 && j - 1 < 0) {
					i--;
					continue;
				}
				else
					break;
			}
			if (dp[i - 1][j] > dp[i][j - 1]) {
				i--;
				continue;
			}
			else {
				j--;
				continue;
			}
		}
	}
	cout << answer.size() << endl;
	for (int i = answer.size()-1; i>=0; i--)
		cout << answer[i];
	cout << "\n";
}