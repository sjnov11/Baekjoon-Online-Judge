#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, T;
int group_cnt = 0;

class Base {
public:
	int x, y;
	int R;
	int group_num;

	Base(int x, int y, int r) {
		this->x = x;
		this->y = y;
		this->R = r;
		this->group_num = 0;
	}
};

vector<Base*> base_list;

bool connect(Base* b1, Base* b2) {
	return pow(b1->R + b2->R, 2) >= (pow(b1->x - b2->x, 2) + pow(b1->y - b2->y, 2));
}

void DFS(Base* b) {
	//if (b.group_num != 0) return;
	b->group_num = group_cnt;
	for (int i = 0; i < base_list.size(); i++) {
		if (connect(b, base_list[i]) && base_list[i]->group_num == 0) {
			DFS(base_list[i]);
		}
	}
}


int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		cin >> N;

		for (int i = 0; i < N; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			base_list.push_back(new Base(x, y, r));
		}

		for (int i = 0; i < N; i++) {
			if (base_list[i]->group_num != 0) continue;
			group_cnt++;

			DFS(base_list[i]);
		}

		cout << group_cnt << endl;

		group_cnt = 0;		
		for (int i = 0; i < N; i++) {
			free(base_list[i]);
		}
		base_list.clear();
	}

}