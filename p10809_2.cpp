#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	char S[101];
	int answer[26];
	memset(answer, -1, sizeof(int) * 26);
	scanf("%s", S);
	
	for (int i = 0; i < strlen(S); i++) {
		if (answer[(S[i] - 'a')] == -1)
			answer[(S[i] - 'a')] = i;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");

}