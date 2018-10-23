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
		
		// Opener �� ���
		if (c == '(' || c == '[') {
			p_stack.push(string(1,c));
		}
			

		// Closure�� ���
		else {
			string pair;		// ��ȣ ¦ ã��
			if (c == ')')
				pair = "(";
			else if (c == ']')
				pair = "[";

			// stack���� ������ ���� �����ֱ� ���� ����
			int num = 0;

			while (true) {
				// Ž�� �Ұ�
				if (p_stack.empty()) {					
					cout << 0 << endl;
					return 0;
				}

				string t = p_stack.top();
				p_stack.pop();

				// Opener ���
				if (t == "[" || t == "(") {
					// ¦�� ���� ������ false
					if (t != pair) {
						cout << 0 << endl;
						return 0;
					}
					else {
						// �߰��� ���ڰ� ���� ���
						if (num == 0) {
							p_stack.push(t == "[" ? "3" : "2");
						}
						// �߰��� ���ڰ� ������ ���
						else {
							t == "[" ? num *= 3 : num *=2;
							p_stack.push(to_string(num));
							num = 0;
						}
						// ¦�� ã������ ���� �Է� ����
						break;
					}
					
				}				
				// Opener �� �ƴ϶�� ������ ���̴�. �����ش�.
				else {
					num += stoi(t);
				}
			}
		}
	}
	int result = 0;
	
	while (!p_stack.empty()) {
		// ¦�� ��ã�� ��ȣ�� ������ false
		if (p_stack.top() == "(" || p_stack.top() == "[") {
			cout << 0 << endl;
			return 0;
		}
		result += stoi(p_stack.top());
		s.pop();
	}
	cout << result << endl;
}