#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Node {
public:
	int val;
	map<int, Node*> adj_list;


	Node(int num) {
		val = num;
	}
	void addAdjacentNode(Node* n) {		
		//adj_list.push_back(n);
		if (adj_list.find(n->val) == adj_list.end()) {
			adj_list.insert(pair<int, Node*>(n->val, n));
		}
	}
};

void DFS(Node* n, bool* visited) {
	cout << n->val << endl;
	visited[n->val] = true;
	map<int, Node*>::iterator it;
	
	for (it = n->adj_list.begin(); it != n->adj_list.end(); it++) {		
		//cout << n->val << "에서 " << it->first << "/ 방문여부 : " << (visited[it->first] ? "방문" : "아직") << endl;
		if (!visited[it->first])
			DFS(it->second, visited); 
	}
}

void BFS(Node* n, bool* visited) {
	queue<Node*> q;
	q.push(n);
	visited[n->val] = true;
	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();
		cout << cur->val << endl;
		map<int, Node*>::iterator it;
		for (it = cur->adj_list.begin(); it != cur->adj_list.end(); it++) {
			if (!visited[it->first]) {
				q.push(it->second);
				visited[it->first] = true;
			}
				
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	vector<Node*> node_list;

	for (int i = 1; i <= N; i++) {
		node_list.push_back(new Node(i));
	}

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		node_list[start - 1]->addAdjacentNode(node_list[end - 1]);
		node_list[end - 1]->addAdjacentNode(node_list[start - 1]);
	}

	//cout << node_list[0]->adj_list.size() << endl;
	bool* visited = (bool*)malloc(sizeof(bool) * N);
	for (int i = 0; i <= N; i++) {
		visited[i] = false;
	}
	//cout <<  "???" << node_list[V - 1]->val << endl;
	DFS(node_list[V - 1], visited);

	for (int i = 0; i <= N; i++) {
		visited[i] = false;
	}
	
	BFS(node_list[V - 1], visited);
}