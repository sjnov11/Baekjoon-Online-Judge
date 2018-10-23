#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	char cur = 'a';
	int alphabet[26];

	for (int i = 0; i < 26; i++) {
		alphabet[i] = -1;
	}
	//for (int i = 0; i < 26; i++) {
	//	bool flag = false;
	//	for (int j = 0; j < s.length(); j++) {
	//		if (s[j] == (char)(cur + i)) {
	//			cout << j << " ";
	//			flag = true;
	//			break;
	//		}
	//	}
	//	if (!flag)
	//		cout << -1 << " ";
	//}

	for (int i = 0; i < s.length(); i++) {
		if (alphabet[s[i] - 'a'] == -1)
			alphabet[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";

	}



}