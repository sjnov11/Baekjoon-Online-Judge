#include <iostream>
using namespace std;

int main() {

	int  T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int A, B;
		cin >> A >> B;
		if (A < B) {
			int temp = B;
			B = A;
			A = temp;
		}
		int ta = A, tb = B;
		while (tb != 0) {
			int temp = ta % tb;
			ta = tb;
			tb = temp;
		}
		cout << A*B / ta << endl;
	}
}