#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[9][9];
vector<pair<int, int>> cctv_list;
int answer = 9999999;

void go(int n, int m, int cur, int cmap[][9]) {
	if (cur == cctv_list.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cmap[i][j] == 0) cnt++;
			}
		}
		answer = min(answer, cnt);
		return;
	}

	auto cur_cctv = cctv_list[cur];
	int cr = cur_cctv.first; 
	int cc = cur_cctv.second; 
	int type = cmap[cr][cc];
	int par_map[9][9];

	if (type == 1) {		
		// Up
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr--;
		}
		go(n, m, cur + 1, par_map);

		// Down		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr++;
		}
		go(n, m, cur + 1, par_map);

		// Left		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc--;
		}
		go(n, m, cur + 1, par_map);

		// Right		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc++;
		}
		go(n, m, cur + 1, par_map);
	}
	else if (type == 2) {
		// Up Down
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr++;
		}
		go(n, m, cur + 1, par_map);

		// Left Right
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc++;
		}
		go(n, m, cur + 1, par_map);
	}
	else if (type == 3) {
		// Up
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc++;
		}
		go(n, m, cur + 1, par_map);

		// Right Down
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc++;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr++;
		}
		go(n, m, cur + 1, par_map);

		// Down Left
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr++;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc--;
		}
		go(n, m, cur + 1, par_map);

		// Left Up
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr--;
		}
		go(n, m, cur + 1, par_map);
	}
	else if (type == 4) {
		// Except Down
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc++;
		}
		go(n, m, cur + 1, par_map);

		// Except Left
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc++;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr++;
		}
		go(n, m, cur + 1, par_map);

		// Except Up
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc++;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr++;
		}
		go(n, m, cur + 1, par_map);

		// Except Right
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr++;
		}
		go(n, m, cur + 1, par_map);
	}
	else if (type == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				par_map[i][j] = cmap[i][j];
			}
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc--;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc--;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cc++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cc++;
		}
		cr = cur_cctv.first;
		cc = cur_cctv.second;
		cr++;
		while (par_map[cr][cc] != 6 && cr >= 0 && cr < n && cc >= 0 && cc < m) {
			if (par_map[cr][cc] == 0) {
				par_map[cr][cc] = -1;
			}
			cr++;
		}
		go(n, m, cur + 1, par_map);
	}
	
}


int main() {
	int N, M; 
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv_list.push_back({ i,j });
			}
		}
	}
	go(N, M, 0, map);
	cout << answer << endl;
	
}