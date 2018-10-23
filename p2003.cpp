#include <cstdio>
using namespace std;

int go(int A[10000], int N, int M) {
	int s = 0, e = 0; 
	int answer = 0;
	int sum = 0;
	while (true) {
		// s 증가
		if (sum >= M) sum -= A[s++];
		// e 증가
		else if (e == N) break;
		else sum += A[e++];
		// 정답 확인
		if (sum == M) answer++;

	}
	return answer;

}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int A[10000];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	printf("%d\n", go(A, N, M));
}