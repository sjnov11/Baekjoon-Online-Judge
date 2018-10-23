#include <iostream>
using namespace std;

int Answer = 0;


int main() {
	int N;
	cin >> N;

	

	for (int i = 1; i <= N; i++) {
		int temp = i;
		while (temp % 5 == 0) {
			temp /= 5;
			Answer++;
		}			
	}
	
	cout << Answer << endl;
	return 0;
}