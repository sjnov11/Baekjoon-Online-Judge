#include <iostream>
#include <vector>
using namespace std;

vector<int> adj_list[101];
bool visited[101];
int Answer = 0;

void DFS(int node) {
	//cout << "visited : " << node << endl;
	visited[node] = true;
	Answer++;
	for (int i = 0; i < adj_list[node].size(); i++) {
		if (!visited[adj_list[node][i]])
			DFS(adj_list[node][i]);
	}
}


int main() {
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	DFS(1);
	cout << Answer-1 << endl;
}
