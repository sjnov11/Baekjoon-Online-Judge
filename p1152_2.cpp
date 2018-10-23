#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char S[1000001];
	scanf("%[^\n]s", S);
	int answer = 0;
	char* word = strtok(S, " ");
	while (word != nullptr) {
		answer++;
		word = strtok(NULL, " ");
	}
	printf("%d\n", answer);
	

}