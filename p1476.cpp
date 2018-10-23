#include <cstdio>
using namespace std;

int main() {
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);
	E = E == 15 ? 0 : E;
	S = S == 28 ? 0 : S;
	M = M == 19 ? 0 : M;
	for (int year = 1; ; year++) {
		if (year % 15 == E && year % 28 == S && year % 19 == M) {
			printf("%d\n",year);
			return 0;
		}
		
	}
}

