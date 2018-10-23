#include <iostream>
using namespace std;

int main() {
	int answer = 0;
	int cur = 0;
	for (int i = 0; i < 4; i++) {
		int a, b;
		cin >> a >> b;
		cur += (b - a);
		if (answer < cur) answer = cur;
	}
	cout << answer << endl;
}