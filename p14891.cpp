#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string topni[4];
// 12시 0 , 오른쪽 2, 왼쪽 6

void spin(int n, int dir, int side) {	
	// left
	if (side == -1 || side == 0) {
		if (n - 1 >= 0 && topni[n - 1][2] != topni[n][6])
			spin(n - 1, dir*(-1), -1);
	}
	// right
	if (side == 1 || side == 0) {
		if (n + 1 < 4 && topni[n + 1][6] != topni[n][2])
			spin(n + 1, dir*(-1), 1);
	}

	if (dir == -1) {
		topni[n].push_back(*topni[n].begin());
		topni[n].erase(topni[n].begin());		
	}
	else {
		string s(1, topni[n][topni[n].size() - 1]);
		topni[n].pop_back();
		topni[n].insert(0, s);
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		cin >> topni[i];
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int n, dir;
		cin >> n >> dir;
		spin(n - 1, dir, 0);
	}
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (topni[i][0] == '1')
			answer += pow(2, i);
	}
	cout << answer << endl;
}