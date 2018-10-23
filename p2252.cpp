#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;
stack<int> s;

void topological_sort(int n) {
	visited[n] = true;

	for (int i = 0; i < adj_list[n].size(); i++) {
		if (!visited[adj_list[n][i]])
			topological_sort(adj_list[n][i]);
	}
	s.push(n);
}


int main() {
	int N, M;
	cin >> N >> M;

	adj_list.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj_list[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i])
			topological_sort(i);
	}

	while (!s.empty()) {
		int n = s.top();
		s.pop();
		cout << n << " ";
	}
	cout << "\n";
}