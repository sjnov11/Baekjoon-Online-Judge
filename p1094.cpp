#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> bars;

//bool cmp(int& a, int& b) {
//	return a > b;
//}


int main() {
	int X;
	cin >> X;
	bars.push_back(64);

	while (true) {
		int sum = 0;
		for (auto b : bars)
			sum += b;
		if (X >= sum) break;
		if (X < sum) {
			sort(bars.begin(), bars.end());
			bars[0] /= 2;
			int sum2 = 0;
			for (auto b : bars)
				sum2 += b;
			if (sum2 < X) {
				bars.push_back(bars[0]);
			}
		}
	}
	cout << bars.size() << endl;
}