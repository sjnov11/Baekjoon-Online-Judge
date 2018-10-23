#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}


bool next_permutation(int *a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) {
		i--;
	}
	if (i == 0) return false;
	int j = n - 1;
	while (j >= i && a[j] <= a[i - 1]) {
		j--;
	}
	swap(&a[i - 1], &a[j]);
	int k = n - 1;
	while (i < k) {
		swap(&a[i], &a[k]);
		i++; k--;
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	int A[10001];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	if (next_permutation(A, N)) {
		for (int i = 0; i < N; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}
	else
		cout << -1 << endl;
}