#include <cstdio>
#include <vector>
using namespace std;


int main() {	
	int N;
	scanf("%d", &N);
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int B,C;
	scanf("%d %d", &B, &C);

	long long answer = 0;
	for (int i = 0; i < N; i++) {
		answer++;
		if (A[i] <= B) continue;
		answer += (A[i] - B) / C;
		answer += (A[i] - B) % C == 0 ? 0 : 1;
	}
	printf("%lld\n", answer);

}