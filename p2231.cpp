#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	for (int con = 1; con <= N; con++) {
		int sum = con;
		int cur = con;
		while (cur != 0) {
			sum += cur % 10;
			cur /= 10;
		}
		//cout << "con: " << con << " / " <<  sum << endl;
		if (sum == N) {
			cout << con << "\n";
			return 0;
		}

	}
	cout << 0 << "\n";
	return 0;
}