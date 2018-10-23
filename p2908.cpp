#include <cstdio>
#include <cstdlib>
using namespace std;

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	char A[4], B[4];
	scanf("%s %s", A, B);
	swap(&A[0], &A[2]);
	swap(&B[0], &B[2]);
	int a = atoi(A);
	int b = atoi(B);
	if (a > b)
		printf("%d\n", a);
	else
		printf("%d\n", b);
}
