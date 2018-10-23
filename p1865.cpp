#include <iostream>
#include <vector>
using namespace std;

#define INF 99999999

vector<pair<int, int>> adj_list[501];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, M, W;
		cin >> N >> M >> W;
		for (int i = 1; i <= 500; i++) {
			adj_list[i].clear();
		}

		for (int i = 0; i < M; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			adj_list[S].push_back(make_pair(E, T));
			adj_list[E].push_back(make_pair(S, T));
		}

		for (int i = 0; i < W; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			adj_list[S].push_back(make_pair(E, T*(-1)));
		}

		int dist[501];
		for (int i = 1; i <= 500; i++) {
			dist[i] = INF;
		}
		dist[1] = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int u = 1; u <= N; u++) {
				if (dist[u] == INF) continue;
				for (auto edge : adj_list[u]) {
					int v = edge.first;
					int w = edge.second;

					if (dist[v] > dist[u] + w)
						dist[v] = dist[u] + w;
				}
			}
		}
		bool cycle = false;
		for (int u = 1; u <= N; u++) {
			if (dist[u] == INF) continue;
			for (auto edge : adj_list[u]) {
				int v = edge.first;
				int w = edge.second;

				if (dist[v] > dist[u] + w) {
					//cout << "YES\n";
					cycle = true;
					break;
					//return 0;
				}				
			}
		}
		if (!cycle) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
	
}
