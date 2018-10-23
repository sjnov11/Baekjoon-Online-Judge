#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> h(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}

		stack<int> s;
		long long Answer = 0;
		for (int i = 0; i < n; i++) {
			while (true) {
				if (s.empty())
					s.push(i);
				else {
					int top_idx = s.top();
					if (h[top_idx] > h[i]) {
						int right = i - 1;
						int left;
						s.pop();
						if (s.empty())
							left = 0;
						else
							left = s.top() + 1;
						Answer = max(Answer, (long long)(right - left + 1) * (long long)h[top_idx]);
					}
					else {
						s.push(i);
						break;
					}
				}
			}
		}

		int right = n - 1;
		while (!s.empty()) {
			int height = h[s.top()];
			int left;
			s.pop();
			if (s.empty())
				left = 0;
			else
				left = s.top() + 1;

			Answer = max(Answer, (long long)height * (long long)(right - left + 1));

		}
		cout << Answer << endl;
	}
}