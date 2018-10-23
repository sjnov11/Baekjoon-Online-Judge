#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<string> p_stack;
	
	char c;
	while (c = cin.get()) {
		if (c == EOF || c== '\n')
			break;
		
		// Opener 일 경우
		if (c == '(' || c == '[') {
			p_stack.push(string(1,c));
		}
			

		// Closure일 경우
		else {
			string pair;		// 괄호 짝 찾기
			if (c == ')')
				pair = "(";
			else if (c == ']')
				pair = "[";

			// stack에서 나오는 숫자 더해주기 위한 변수
			int num = 0;

			while (true) {
				// 탐색 불가
				if (p_stack.empty()) {					
					cout << 0 << endl;
					return 0;
				}

				string t = p_stack.top();
				p_stack.pop();

				// Opener 경우
				if (t == "[" || t == "(") {
					// 짝이 맞지 않으면 false
					if (t != pair) {
						cout << 0 << endl;
						return 0;
					}
					else {
						// 중간에 숫자가 없는 경우
						if (num == 0) {
							p_stack.push(t == "[" ? "3" : "2");
						}
						// 중간에 숫자가 더해진 경우
						else {
							t == "[" ? num *= 3 : num *=2;
							p_stack.push(to_string(num));
							num = 0;
						}
						// 짝을 찾았으니 다음 입력 받자
						break;
					}
					
				}				
				// Opener 가 아니라면 숫자일 것이다. 더해준다.
				else {
					num += stoi(t);
				}
			}
		}
	}
	int result = 0;
	
	while (!p_stack.empty()) {
		// 짝을 못찾은 괄호가 있으면 false
		if (p_stack.top() == "(" || p_stack.top() == "[") {
			cout << 0 << endl;
			return 0;
		}
		result += stoi(p_stack.top());
		s.pop();
	}
	cout << result << endl;
}