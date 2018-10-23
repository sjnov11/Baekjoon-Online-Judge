#include <iostream>
using namespace std;

long long cache[1001][1001];
const int MOD = 10007;

long long combination(int n, int k) {
	if (k == 0) {
		cache[n][k] = 1;		
	}
	
	if (n == k) {
		cache[n][k] = 1;		
	}
		
	if (cache[n][k] > 0) 
		return cache[n][k];
	cache[n][k] = (combination(n - 1, k - 1) + combination(n - 1, k)) % MOD;
	return cache[n][k];
}


int main() {
	int N, K;
	cin >> N >> K;
	if (K > N / 2)
		K = N - K;
	cout << combination(N, K) % MOD<< endl;
}