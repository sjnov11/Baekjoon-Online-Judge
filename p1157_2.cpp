#include <cstdio>
#include <cstring>
using namespace std;


int main() {
	char S[1000001];
	scanf("%s", S);
	int s_len = strlen(S);
	for (int i = 0; i < s_len; i++) {
		if (S[i] < 'a') {
			S[i] = char(S[i] - 'A' + 'a');
		}
	}
	int answer[26];
	memset(answer, 0, sizeof(int) * 26);
	for (int i = 0; i < s_len; i++) {
		answer[S[i] - 'a']++;
	}
	int first_idx = -1;
	int first_val = -1;
	int second_idx = -1;
	int second_val = -1;
	for (int i = 0; i < 26; i++) {
		if (first_val < answer[i]) {
			second_idx = first_idx;
			second_val = first_val;
			first_idx = i;
			first_val = answer[i];
		}
		else if (second_val < answer[i]) {
			second_idx = i;
			second_val = answer[i];
		}
	}
	if (first_val == second_val)
		printf("?\n");
	else
		printf("%c\n", char('A' + first_idx));
}