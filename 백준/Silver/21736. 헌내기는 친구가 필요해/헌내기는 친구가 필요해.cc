#include <iostream>
#include <vector>
#include <queue>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
	SWS;
	int n, m, ans = 0;
	cin >> n>> m;
	vector<vector<char>> v(n, vector<char>(m));
	vector<vector<bool>> vst(n, vector<bool>(m, false));
	queue<pair<int, int>> q;
	pair<int, int> pos[4] = { {1,0},{-1,0},{0,1},{0,-1} };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'I') {
				q.push({ i,j });
				vst[i][j];
			}
		}
	}
	while (!q.empty()) {
		int r = q.front().first, c = q.front().second;
		q.pop();
		for (auto it : pos) {
			int nr = r + it.first, nc = c + it.second;
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (v[nr][nc]=='X'||vst[nr][nc]) continue;
			if (v[nr][nc] == 'P') ans++;
			vst[nr][nc] = true;
			q.push({ nr,nc });
		}
	}
	(ans == 0 ? cout << "TT" : cout << ans);
	return 0;
}