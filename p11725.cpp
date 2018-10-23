#include <iostream>
#include <list>
#include <vector>
#include <set>
using namespace std;


class Node {
public:
	int value;
	bool visited;
	int parent;
	vector<Node*> conn_list;

	Node(int num) {
		this->value = num;
		this->visited = false;
	}
};


void traverse(Node* node, int parent) {	
	if (node->visited)
		return;
	node->parent = parent;
	node->visited = true;
	for (int i = 0; i < node->conn_list.size(); i++) {
		traverse(node->conn_list[i], node->value);
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<Node*> node_list(N + 1);
	
	for (int i = 1; i <= N; i++) {
		node_list[i] = new Node(i);
	}


	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		node_list[n1]->conn_list.push_back(node_list[n2]);
		node_list[n2]->conn_list.push_back(node_list[n1]);
	}

	traverse(node_list[1], 0);

	for (int i = 2; i <= N; i++) {
		cout << node_list[i]->parent << '\n';
	}


}