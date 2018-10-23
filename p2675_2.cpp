#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int R;
		scanf("%d", &R);
		char S[21];
		scanf("%s", S);
		char* new_S = new char[strlen(S)*3 + 1];
		for (int i = 0; i < strlen(S); i++) {
			for (int j = 0; j < R; j++) {
				new_S[i*R + j] = S[i];
			}
		}
		new_S[strlen(S)*R] = '\0';
		printf("%s\n", new_S);
	}

}