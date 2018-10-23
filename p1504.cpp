#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj_list[801];

vector<int> dijkstra(int start, int end, int V) {
	vector<int> dist(V + 1, 999999);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cur_cost = pq.top().first * (-1);
		pq.pop();

		if (dist[cur] <= cur_cost) continue;
		dist[cur] = cur_cost;
		if (cur == end)
			return dist;

		for (auto adj : adj_list[cur]) {
			int next = adj.first;
			int next_cost = cur_cost + adj.second;

			pq.push(make_pair(next_cost*(-1), next));
		}
	}

	return dist;

}


int main() {
	int N, E;
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj_list[a].push_back(make_pair(b, c));
		adj_list[b].push_back(make_pair(a, c));
	}
	int n1, n2;
	cin >> n1 >> n2;
	long long answer = 0;
	answer += dijkstra(1, n1, N)[n1];
	answer += dijkstra(n1, n2, N)[n2];
	answer += dijkstra(n2, N, N)[N];

	long long answer2 = 0;
	answer2 += dijkstra(1, n2, N)[n2];
	answer2 += dijkstra(n2, n1, N)[n1];
	answer2 += dijkstra(n1, N, N)[N];

	answer = min(answer, answer2);
	if (answer >= 999999)
		cout << -1 << endl;
	else
		cout << answer << "\n";

}