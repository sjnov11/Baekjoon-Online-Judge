#include <iostream>
using namespace std;

int perm[1001];
bool visited[1001];

void DFS(int num) {
	visited[num] = true;

	if (!visited[perm[num]])
		DFS(perm[num]);
}

int main() {
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {


		int N;
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> perm[i];
			visited[i] = false;
		}

		int answer = 0;
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			DFS(i);
			answer++;
		}
		cout << answer << endl;

	}
}