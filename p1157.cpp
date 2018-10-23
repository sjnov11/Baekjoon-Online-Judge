#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int alpha_cnt[26];

	for (int i = 0; i < 26; i++) {
		alpha_cnt[i] = 0;
	}

	int diff_upper_lower = 'a' - 'A';

	for (int i = 0; i < s.length(); i++) {
		int idx = (int)s[i] > (int)'Z' ? s[i] - diff_upper_lower : s[i];
		idx -= 'A';
		alpha_cnt[idx]++;
	}

	int most_alpha_cnt = 0;
	int most_alpha_idx = 0;
	bool overlapped = false;
	for (int i = 0; i < 26; i++) {
		if (alpha_cnt[i] > most_alpha_cnt) {
			most_alpha_cnt = alpha_cnt[i];
			most_alpha_idx = i;
			overlapped = false;
		}
		else if (alpha_cnt[i] == most_alpha_cnt) {
			overlapped = true;
		}
	}

	cout << (overlapped ? '?' : (char)('A'+most_alpha_idx)) << endl;
}