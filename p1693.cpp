#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string.h>
using namespace std;


int dp[100001][18];

class Node {
public:
	int val;
	vector<Node*> adj_list;

	Node(int val) {
		this->val = val;
	}

};

int solve(Node* node, int color, bool* visited) {
	//cout << "node: " << node->val << " /  color : " << color << "/ visited : " << visited[node->val] << endl;
	if (dp[node->val][color] > 0)
		return dp[node->val][color];

	visited[node->val] = true;

	vector<Node*>::iterator adj_it;
	int result = 0;
	for (adj_it = node->adj_list.begin(); adj_it != node->adj_list.end(); ++adj_it) {
		if (visited[(*adj_it)->val]) continue;
		int answer = INT_MAX;
		for (int i = 1; i <= 17; i++) {
			if (i == color) continue;
			answer = min(answer, solve(*adj_it, i, visited));
			visited[(*adj_it)->val] = false;
		}
		//visited[(*adj_it)->val] = true;
		result += answer;
	}
	//cout << "dp[" << node->val << "][" << color << "]: " << result + color << endl;
	return dp[node->val][color] = result + color;
}


int main() {
	
	int n;
	cin >> n;
	vector<Node*> tree(n+1);
	for (int i = 1; i <= n; i++) {
		tree[i] = new Node(i);
	}
	for (int i = 0; i < n - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		
		tree[n1]->adj_list.push_back(tree[n2]);
		tree[n2]->adj_list.push_back(tree[n1]);
		
	}
	bool *visited = new bool[n+1];
	int result = INT_MAX;
	for (int i = 1; i <= 17; i++) {
		memset(visited, false, n + 1);
		int a1 = solve(tree[1], i, visited);
		result = min(result, a1);
	}



	cout << result << '\n';
}