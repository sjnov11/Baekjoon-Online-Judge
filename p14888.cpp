#include <iostream>
#include <algorithm>
using namespace std;

int A[12];
int op[4];
int N;
int max_answer = -1000000002;
int min_answer = 1000000002;


void go(int cnt, int left[4], int result) {
	if (cnt == N) {
		max_answer = max(max_answer, result);
		min_answer = min(min_answer, result);
		return;
	}
	int temp[4];
	for (int i = 0; i < 4; i++) {
		temp[i] = left[i];
	}

	for (int i = 0; i < 4; i++) {
		if (temp[i] == 0) continue;
		
		temp[i]--;
		if (i == 0)	go(cnt + 1, temp, result + A[cnt]);
		else if (i == 1) go(cnt+1, temp, result- A[cnt]);		
		else if (i == 2) go(cnt+1, temp, result * A[cnt]);
		else if (i == 3) go(cnt+1, temp, result / A[cnt]);
		temp[i]++;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];
	go(1, op, A[0]);
	cout << max_answer << endl;
	cout << min_answer << endl;
}
