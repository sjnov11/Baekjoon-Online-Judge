#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


vector<pair<int, int>> adj_list[20001];

vector<int> dijkstra(int V, int start) {
	vector<int> dist(V + 1, INT_MAX);
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, start));
	
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first * (-1);
		pq.pop();

		// 이미 방문했다면 cost 가 이미 최소로 줄었다
		// 현재 이진힙의 cost가 dist보다 크면 이미 방문하여 업뎃한 곳
		if (dist[cur] <= cost) continue;
		dist[cur] = cost;

		for (auto adj : adj_list[cur]) {
			int next = adj.first;
			int next_cost = cost + adj.second;

			pq.push(make_pair(next_cost*(-1), next));
		}
	}
	return dist;
}


int main() {
	int V, E;
	cin >> V >> E;
	int K;
	cin >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj_list[u].push_back(make_pair(v, w));
	}

	vector<int> answer = dijkstra(V, K);
	for (int i = 1; i <= V; i++) {
		if (answer[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << answer[i] << "\n";
	}
}