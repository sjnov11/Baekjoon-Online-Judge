#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
	d[A][k] k�ڸ������� k��° �ڸ����� A�϶� �������� ����
	9876543210
*/

int d[10][11];
string result[1000001];
map<pair<int, int>, int> m;

int main() {
	int N;
	cin >> N;
	// �� �ڸ���
	for (int i = 0; i < 10; i++) {
		d[i][1] = 1;
		result[i] = to_string(i);
		m[{i, 1}] = i;		
	}
	int cnt = 9;

	for (int i = 2; i <= 10; i++) {						// i �ڸ���
		for (int j = i - 1; j <= 9; j++) {				// ù��° ����
			
			d[j][i] = d[j - 1][i] + d[j - 1][i - 1];
			m[{j, i}] = cnt + 1;

			//cout << "d[" << j << "][" << i << "] : " << d[j][i] << endl;
			//cout << "m[{" << j << ", " << i << "}] : " << m[{j, i}] << endl;
			// j-1, i �� ���� �ε��� ~ i ���� �� ������ŭ (i~ i+d[j-1][i] - 1)
			int idx = m[{j - 1, i}];
			for (int a = idx; a < idx + d[j - 1][i]; a++) {
				result[++cnt] = to_string(j) + result[a].substr(1);
				//cout << "result[" << cnt << "] : " << result[cnt] << endl;
			}
			idx = m[{j - 1, i - 1}];
			for (int a = idx; a < idx + d[j - 1][i - 1]; a++) {
				result[++cnt] = to_string(j) + result[a];
				//cout << "result[" << cnt << "] : " << result[cnt] << endl;
			}
			if (cnt >= N) {				
				cout << result[N] << '\n';
				return 0;
			}			
		}
	}
	cout << -1 << endl;
	//cout << result[N] << '\n';
}