#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 999999

vector<int> adj_list[501];
int time[501];
int indegree[501];
int answer[501];


int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> time[i];
		while (true) {
			int build_num;
			cin >> build_num;
			if (build_num == -1) break;
			adj_list[build_num].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			answer[i] = time[i];
		}
	}

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		for (int next : adj_list[n]) {
			if (answer[next] < answer[n] + time[next]) {
				answer[next] = answer[n] + time[next];
			}
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << answer[i] << "\n";
	}

}