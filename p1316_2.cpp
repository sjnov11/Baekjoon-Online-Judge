#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int answer = 0;
	for (int n = 0; n < N; n++) {
		char word[101];
		scanf("%s", word);
		int len = strlen(word);
		bool used[26];
		memset(used, false, sizeof(bool) * 26);

		bool is_group = true;
		char cur = word[0];
		used[word[0] - 'a'] = true;
		for (int i = 1; i < len; i++) {
			if (cur == word[i]) continue;
			if (used[word[i] - 'a']) {
				is_group = false;
				break;
			}
			used[word[i] - 'a'] = true;
			cur = word[i];
		}
		if (is_group) answer++;
	}
	printf("%d\n", answer);
}