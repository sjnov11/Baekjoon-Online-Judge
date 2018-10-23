#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	char alpha;
	Node* child[2];

	Node() {
		alpha = NULL;
		child[0] = NULL;
		child[1] = NULL;
	}
};

void preorder(Node* node) {
	if (node == NULL)
		return;
	cout << node->alpha;
	preorder(node->child[0]);
	preorder(node->child[1]);
}
void inorder(Node* node) {
	if (node == NULL)
		return;
	inorder(node->child[0]);
	cout << node->alpha;
	inorder(node->child[1]);
}
void postorder(Node* node) {
	if (node == NULL)
		return;
	postorder(node->child[0]);
	postorder(node->child[1]);
	cout << node->alpha;
}

int main() {
	int N;
	cin >> N;

	vector<Node*> node_list(N);
	
	for (int i = 0; i < N; i++) {
		node_list[i] = new Node();
		node_list[i]->alpha = 'A' + i;
	
	}

	for (int i = 0; i < N; i++) {
		char node, c1, c2;
		cin >> node >> c1 >> c2;

		if (c1 != '.')
			node_list[node - 'A']->child[0] = node_list[c1 - 'A'];
		if (c2 != '.')
			node_list[node - 'A']->child[1] = node_list[c2 - 'A'];
	}


	preorder(node_list[0]);
	cout << endl;
	inorder(node_list[0]);
	cout << endl;
	postorder(node_list[0]);
	cout << endl;


}