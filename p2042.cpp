#include <iostream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;


long long buildSegTree(vector<long long> &arr, vector<long long> &seg_tree, int node, int start, int end) {
	if (start == end) {
		return seg_tree[node] = arr[start];
	}
	else {
		return seg_tree[node] = buildSegTree(arr, seg_tree, node * 2, start, (start + end) / 2) + buildSegTree(arr, seg_tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
	//return seg_tree[node];
}

long long getPartialSum(vector<long long>&seg_tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && right >= end)
		return seg_tree[node];
	return getPartialSum(seg_tree, node * 2, start, (start + end) / 2, left, right) + getPartialSum(seg_tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long> &seg_tree, int node, int start, int end, int idx, long long diff) {
	if (start > idx || end < idx)
		return;
	seg_tree[node] += diff;
	if (start != end) {
		update(seg_tree, node * 2, start, (start + end) / 2, idx, diff);
		update(seg_tree, node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	vector<long long> arr;
	arr.push_back(-1);
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		arr.push_back(num);		
	}
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<long long> seg_tree(tree_size);
	buildSegTree(arr, seg_tree, 1, 1, N);
	int n = 1;
	/*for (int i = 1; i < N *2; i++) {
		cout << seg_tree[i] << " ";
		if (i == n) {
			cout << endl;
			n = n * 2 + 1;
		}
	}*/
	for (int i = 0; i < M + K; i++) {
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 1) {			
			update(seg_tree, 1, 1, N, a, b - arr[a]);
			arr[a] = b;
		}
		else if (op == 2) {
			cout << getPartialSum(seg_tree, 1, 1, N, a, b) << endl;;
		}
	}


	
}