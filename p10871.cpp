#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	int N, X;
	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		int cur;
		cin >> cur;
		if (cur < X) {
			cout << cur << " ";
		}
	}
	cout << endl;

	return 0;

}