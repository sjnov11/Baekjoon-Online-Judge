#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];
bool visited[1001];

int MST() {
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, 1));
	int cnt = 0;
	int ret = 0;
	while (!q.empty()) {
		int cur = q.top().second;
		int cur_w = q.top().first;
		q.pop();

		if (visited[cur]) continue;
		visited[cur] = true;
		ret += cur_w * (-1);
		cnt++;
		if (cnt == N) break;
		for (auto next : graph[cur]) {
			int v = next.first;
			int w = next.second * (-1);
			q.push(make_pair(w, v));
		}
	}
	return ret;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,c));
	}

	cout << MST() << endl;
}