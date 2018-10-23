#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	
	stack<int> s;

	int N;
	cin >> N;
	string result;
	int cur = 1;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		
		while (cur <= num) {
			s.push(cur++);
			//cout << "+" << endl;				
			result += "+\n";
		}
		
		if (s.size() == 0) {
			//cout << s.size() << endl;
			result = "NO";
		}
		
		while (!s.empty() && s.top() > num) {
			s.pop();
			//cout << "-" << endl;
			result += "-\n";
		}
		if (s.empty()) {
			result = "NO\n";
			break;
		}
		if (s.top() == num) {
			s.pop();
			//cout << "-" << endl;
			result += "-\n";
		}

	}
	cout << result;
}