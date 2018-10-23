#include <iostream>
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;

	while (true) {
		if (L > 100) break;
		int k = N / L;
		while (true) {
			int sum = 0;
			for (int i = 0; i < L; i++) {
				sum += k + i;
			}
			if (sum == N) {
				for (int i = 0; i < L; i++) {
					cout << k + i << " ";
				}
				cout << "\n";
				return 0;
			}
			else if (sum > N) {
				if (k == 0) break;
				else 
					k--;
			}
			else
				break;
		}
		L++;
	}
	cout << "-1\n";
}