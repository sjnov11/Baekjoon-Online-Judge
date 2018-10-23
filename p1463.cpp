#include <iostream>
#include <algorithm>
using namespace std;

#define INF 999999

int main() {
	int X;
	cin >> X;
	int* dp = new int[X + 1];

	dp[1] = 0;

	

	for (int i = 2; i <= X; i++) {
		int a = i % 3 == 0 ? dp[i / 3] : INF;
		int b = i % 2 == 0 ? dp[i / 2] : INF;
		int c = dp[i - 1];		
		
		dp[i] = min(min(a, b), c) + 1;
	}
	cout << dp[X] << endl;
}



/*
 10 5 4 2 1  에에엑
 10 9 3 1  더빠르다. 즉, 순서대로되는걸 하는것 x
 
 dp[x] 
 int a = x % 3 == 0 ? dp[x/3] : 999999;
 int b = x % 2 == 0 ? dp[x/2] : 999999;
 int c = dp[x-1];

 dp[x] = min (a,b,c) + 1

*/