#include <iostream>
using namespace std;

int Tri[46];

int main() {
	for (int i = 1; i <= 45; i++) {
		Tri[i] = i*(i + 1) / 2;
	}
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int K;
		cin >> K;

		bool pos = false;
		for (int i = 1; i <= 45; i++) {
			for (int j = 1; j <= 45; j++) {
				for (int k = 1; k <= 45; k++) {
					if (Tri[i] + Tri[j] + Tri[k] == K) {
						pos = true;
						cout << "1\n";
						i = 45;
						j = 45;
						k = 45;
					}
				}
			}
		}
		if (!pos) cout << "0\n";
	}
}