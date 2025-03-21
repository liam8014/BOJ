#include <iostream>
#include <vector>
#include <queue>

#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
vector<vector<bool>> v;
vector<vector<bool>> vst;
queue <pair<pair<int, int>,int>> q;
int main() {
	SWS;
	int n, m, ans=0;
	char ch;
	cin >> n >> m;
	v.resize(n, vector<bool>(m));
	vst.resize(n, vector<bool>(m,false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ch;
			v[i][j] = (ch == '1' ? true:false);
		}
	}
	q.push({{ 0,0 }, 1});
	vector<pair<int, int>> pos = { {1,0},{0,1},{-1,0}, {0,-1} };
	while (!q.empty()) {
		int row = q.front().first.first, col = q.front().first.second, cost = q.front().second;
		if (row == n - 1 && col == m - 1) {
			cout << cost;
			return 0;
		}
		vst[row][col] = true;
		q.pop();
		for (auto it : pos) {
			int nrow = row + it.first, ncol = col + it.second;
			if (nrow == n - 1 && ncol == m - 1) {
				cout << cost+1;
				return 0;
			}
			if ((nrow < 0 || nrow >= n) || (ncol < 0 || ncol >= m))continue;
			if (!v[nrow][ncol] || vst[nrow][ncol])continue;
			vst[nrow][ncol] = true;
			q.push({{ nrow,ncol }, cost+1});
		}
	}
	return 0;
}