#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int maxWidth[10001];
int levelWidth[10001];

class Node {
public:
	int val;
	Node* child[2];
	bool isRoot;
	int level;
	Node(int num) {
		this->val = num;
		memset(child, NULL, sizeof(Node*) * 2);
		isRoot = true;
		level = 0;
	}
};

void inorder(Node* node, vector<Node*> &inorder_list, int level) {
	if (node == NULL)
		return;
	inorder(node->child[0], inorder_list, level+1);
	node->level = level;
	inorder_list.push_back(node);
	inorder(node->child[1], inorder_list, level+1);
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<Node*> tree(N+1, NULL);
	for (int i = 1; i <= N; i++) {
		tree[i] = new Node(i);
	}

	for (int i = 0; i < N; i++) {
		int parent, c1, c2;
		cin >> parent >> c1 >> c2;
		if (c1 != -1) {
			tree[parent]->child[0] = tree[c1];
			tree[c1]->isRoot = false;
		}
		if (c2 != -1) {
			tree[parent]->child[1] = tree[c2];
			tree[c2]->isRoot = false;
		}
	}

	Node* root;
	for (int i = 1; i <= N; i++) {
		if (tree[i]->isRoot) {
			root = tree[i];
			break;
		}
	}
	
	vector<Node*> inorder_list;
	inorder(root, inorder_list, 1);

	/*for (int i = 0; i < N; i++) {
		cout << inorder_list[i]->val << "[" <<inorder_list[i]->level << "] ";
	}
	cout << '\n';*/

	int maxLevel = 1;
	int maxWidth = 1;
	for (int level = 1; ; level++) {
		int left = -1;
		int right = -1;

		for (int i = 0; i < N; i++) {
			if (inorder_list[i]->level == level) {
				left = i;
				break;
			}
		}
		if (left == -1)
			break;

		else {
			for (int i = left; i < N; i++) {
				if (inorder_list[i]->level == level) {
					right = i;
				}
			}
		}
		if (right != -1) {
			int width = right - left + 1;
			if (maxWidth < width) {
				maxLevel = level;
				maxWidth = width;
			}
		}
	}
	cout << maxLevel << " " << maxWidth << '\n';
}