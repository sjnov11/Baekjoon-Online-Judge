#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> trust_list[10001];
bool visited[10001];
vector<int> answer;
int N, M;

int DFS(int com_num) {
	visited[com_num] = true;
	int ret = 0;
	for (int i = 0; i < trust_list[com_num].size(); i++) {
		if (!visited[trust_list[com_num][i]]) {
			ret += DFS(trust_list[com_num][i]);
		}
	}
	return ret + 1;
}


int main() {

	cin >> N >> M;



	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		trust_list[b].push_back(a);
	}

	int max_num = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			visited[j] = false;
		}
		int temp = DFS(i);
		if (max_num < temp) {
			answer.clear();
			answer.push_back(i);
			max_num = temp;
		}
		else if (max_num == temp) {
			answer.push_back(i);
		}
		
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	cout << "\n";
}