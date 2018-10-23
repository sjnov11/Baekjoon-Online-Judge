#include <iostream>
#include <string.h>
using namespace std;

long long **cache;

long long combination(int n, int k) {
	/*if (k > n / 2) {
		k = n - k;
	}
	if (k == 0) {
		cache[n][k] = 1;
	}

	if (n == k) {
		cache[n][k] = 1;
	}

	if (cache[n][k] > 0)
		return cache[n][k];
	cache[n][k] = (combination(n - 1, k - 1) + combination(n - 1, k));
	return cache[n][k];*/
	
	for (int i = 1; i <= n; i++) {
		
		cache[i][0] = 1LL;
		if (i <= k)
			cache[i][i] = 1LL;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; (j < i && j <= k); j++) {
			cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];			
		}
	}

	return cache[n][k];
}


int main() {

	while (true) {
		int N, K;
		cin >> N >> K;
		if (N == 0 && K == 0)
			return 0;
		if (N - K < K) {
			K = N - K;
		}

		long long Answer = 1;

		for (long long i = 1; i <= K; i++) {
			Answer = Answer * (N - i + 1);
			Answer = Answer / i;
		}
		cout << Answer << endl;
	}
	
}