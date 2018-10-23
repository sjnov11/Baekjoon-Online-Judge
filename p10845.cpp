#include <iostream>
#include <string>
using namespace std;


class Node {
public:
	int val;
	Node* next;

	Node(int num) {
		val = num;
		next = NULL;
	}
};

class Queue {
public:
	Node* front;
	Node* end;
	int size;
	
	Queue() {
		front = NULL;
		end = NULL;
		size = 0;
	}

	void push(int num) {
		Node* n = new Node(num);
		if (front == NULL) {
			front = n;
			end = n;
		}
		else {
			end->next = n;
			end = n;
		}
		size++;
	}

	int pop() {
		if (size == 0)
			return -1;
		int ret = front->val;
		Node* temp = front;
		front = front->next;
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

	int getFront() {
		if (size == 0)
			return -1;
		return front->val;
	}

	int getBack() {
		if (size == 0)
			return -1;
		return end->val;
	}
};

int main() {
	int N;
	cin >> N;

	Queue q;
	for (int i = 0; i < N; i++) {
		string op;
		cin >> op;

		if (op == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (op == "pop") {
			cout << q.pop() << endl;
		}
		else if (op == "size") {
			cout << q.getSize() << endl;
		}
		else if (op == "empty") {
			cout << q.empty() << endl;
		}
		else if (op == "front") {
			cout << q.getFront() << endl;
		}
		else if (op == "back") {
			cout << q.getBack() << endl;
		}

	}
}