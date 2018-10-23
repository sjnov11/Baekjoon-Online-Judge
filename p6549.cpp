#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;


int buildSegTree(vector<int> &arr, vector<int> &tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = start;
		return start;
	}

	int left = buildSegTree(arr, tree, node * 2, start, (start + end) / 2);
	int right = buildSegTree(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	
	if (arr[left] > arr[right])
		return tree[node] = right;
	else
		return tree[node] = left;
}

int getMinHeightIdx(vector<int> &arr, vector<int> &tree, int node, int start, int end, int left, int right) {
	if (start > right || end < left)
		return 0;
	if (start >= left && end <= right)
		return tree[node];

	int left_idx = getMinHeightIdx(arr, tree, node * 2, start, (start + end) / 2, left, right);
	int right_idx = getMinHeightIdx(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

	if (arr[left_idx] > arr[right_idx]) {
		return right_idx;
	}
	else {
		return left_idx;
	}
}

long long answer(vector<int> &arr, vector<int> &tree, int N, int left, int right) {
	int idx = getMinHeightIdx(arr, tree, 1, 1, N, left, right);
	long long result;
	result = (long long)arr[idx] * (long long)(right - left + 1);
	if (idx - 1 >= left)
		result = max(result, answer(arr, tree, N, left, idx - 1));
	if (idx + 1 <= right)
		result = max(result, answer(arr, tree, N, idx + 1, right));
	
	return result;	
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("input3.txt", "r", stdin);
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		vector<int> arr(N + 1);
		arr[0] = INT_MAX;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}

		int h = ceil(log2(N));
		int tree_size = (1 << (h + 1));
		vector<int> tree(tree_size + 1);
		buildSegTree(arr, tree, 1, 1, N);

		cout << answer(arr, tree, N, 1, N) << endl;
	}
	return 0;
}
