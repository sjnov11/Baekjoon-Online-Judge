#include <iostream>
using namespace std;

int main() {
	int N, a, b;
	cin >> N >> a >> b;
	int answer = 0;
	while (true) {
		answer++;
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
		if (a == b) {
			cout << answer << endl;
			return 0;
		}
	}
}