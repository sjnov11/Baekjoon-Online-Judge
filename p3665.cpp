#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int adj_matrix[501][501];
int order[501];
int indegree[501];
vector<int> answer;
queue<int> q;
int n, m;

void topological_sort() {
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		answer.push_back(cur);

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (adj_matrix[cur][i] == 1) {
				adj_matrix[cur][i] = 0;
				indegree[i]--;
				if (indegree[i] == 0) {
					if (cnt == 1) {
						cout << "?\n";
						return;
					}
					cnt++;
					q.push(i);
				}
			}
		}
	}

	if (answer.size() != n) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	else {
		for (int cur : answer) {
			cout << cur << " ";
		}
		cout << "\n";
	}
}

int main() {
	int T; 
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> n;
		// 순서를 담는 배열
		for (int i = 1; i <= n; i++) {
			cin >> order[i];
		}

		//초기화
		for (int i = 1; i <= n; i++) {
			indegree[i] = 0;
			for (int j = 1; j <= n; j++) {
				adj_matrix[i][j] = 0;
			}
		}
		answer.clear();
		while (!q.empty()) q.pop();

		// 순서를 기반으로 인접행렬 생성
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				adj_matrix[order[i]][order[j]] = 1;
				indegree[order[j]]++;
			}
		}
		cin >> m;
		// 인접행렬 수정
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			if (adj_matrix[a][b] == 1) {
				adj_matrix[b][a] = 1;
				adj_matrix[a][b] = 0;
				indegree[a]++;
				indegree[b]--;
			}
			else {
				adj_matrix[b][a] = 0;
				adj_matrix[a][b] = 1;
				indegree[a]--;
				indegree[b]++;
			}
		}

		// 위상 정렬 수행
		topological_sort();
		
	}
}

