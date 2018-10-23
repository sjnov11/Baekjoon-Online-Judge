#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int a, b;
		cin >> a >> b;

		int x;
		while (a != 0) {
			if (b % a == 0) {
				x = b / a;
			}
			else {
				x = b / a + 1;
			}
			a = a * x - b;
			b = b * x;
		}
		cout << x << "\n";
	}
	
}