#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

vector<int> adj_list[32001];
int indegree[32001];

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj_list[a].push_back(b);
		indegree[b]++;
	}

	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int n = q.top();
		q.pop();
		cout << n << " ";
		for (int next : adj_list[n]) {
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
}