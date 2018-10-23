#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Node{
public:
	int val;
	Node* next;
	Node(int num) {
		val = num;
		next = NULL;
	}
};

class Stack {
public:
	Node* top;
	int size;

	Stack() {
		top = NULL;
		size = 0;
	}

	void push(int num) {
		Node* n = new Node(num);
		if (top == NULL) {			
			top = n;
		}
		else {
			n->next = top;
			top = n;
		}
		size++;
	}

	int pop() {
		if (empty() == 1) {
			return -1;
		}
		int ret = top->val;
		Node* temp = top;
		top = top->next;
		free(temp);
		size--;
		return ret;
	}

	int getSize() {
		return size;
	}

	int empty() {
		return size == 0 ? 1 : 0;
	}

	int getTop() {
		if (empty() == 1) {
			return -1;
		}
		return top->val;
	}
};

int main() {
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	Stack s = Stack();
	for (int i = 0; i < N; i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (order == "pop") {
			cout << s.pop() << endl;
		}
		else if (order == "size") {
			cout << s.getSize() << endl;
		}
		else if (order == "empty") {
			cout << s.empty() << endl;
		}
		else if (order == "top") {
			cout << s.getTop() << endl;
		}
	}
}