#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std; 

int N, M;
int board[21][21];
int answer = 99999999;
vector<pair<int, int>> house_list;
vector<pair<int, int>> chicken_list;


void go(int cur, int cnt, vector<int> select) {	
	if (cnt == M) {
		int result = 0;
		for (auto h : house_list) {
			int dist = 99999999;
			for (auto idx : select) {
				auto c = chicken_list[idx];
				dist = min(dist, abs(c.first - h.first) + abs(c.second - h.second));
			}
			result += dist;
		}		
		answer = min(answer, result);
		return;
	}
	if (cur == chicken_list.size())
		return;
	go(cur + 1, cnt, select);
	select.push_back(cur);
	go(cur + 1, cnt + 1, select);
}

int main() {
	cin >> N >> M;
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;
			if (x == 1) house_list.push_back({ i, j });
			if (x == 2) chicken_list.push_back({ i,j });
		}
	}

	vector<int> temp;
	go(0, 0, temp);

	cout << answer << endl;
}