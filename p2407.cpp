#include <iostream>
using namespace std;

const long long maximum = 1e17;

typedef struct long_num {
	long long front = 0;
	long long end = 0;
} long_num;

long_num operator + (const long_num &num1, const long_num &num2) {
	long_num ret;
	ret.front = num1.front + num2.front;

	if (num1.end + num2.end > maximum) {
		ret.front++;
		ret.end = num1.end + num2.end - maximum;
	}
	else {
		ret.end = (num1.end + num2.end);
	}
	return ret;
	
}

long_num cache[101][101];

long_num combination(int n, int k) {
	if (k > n / 2) {
		k = n - k;
	}
	if (k == 0) {
		cache[n][k].front = 0;
		cache[n][k].end = 1;
	}
	if (n == k) {
		cache[n][k].front = 0;
		cache[n][k].end = 1;
	}
	if (cache[n][k].end != 0 || cache[n][k].front != 0)
		return cache[n][k];

	cache[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
	return cache[n][k];
}


int main() {
	int n, m;
	cin >> n >> m;
	
	long_num ret = combination(n, m);

	if (ret.front != 0)
		cout << ret.front;
	cout << ret.end << endl;
}