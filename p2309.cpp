#include <iostream>
#include <algorithm>
using namespace std;

int h[9];


int go(int n, int s, int sum) {	
	if (s == 7) {
		if (sum == 100) {
			return 1;
		}
		else
			return 0;
	}
	if (n < 0) return 0;
	if (sum >= 100) return 0;

	if (go(n - 1, s + 1, sum + h[n]) == 1) {
		cout << h[n] << endl;
		return 1;
	}
	if (go(n - 1, s, sum) == 1) {
		return 1;
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> h[i];
	}
	sort(h, h+9);
	
	go(8, 0, 0);
}