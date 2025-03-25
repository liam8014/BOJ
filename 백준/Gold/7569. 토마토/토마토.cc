#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
vector<vector<vector<int>>> v;
int M, N, H, ans = 0;
struct tomato {
	int h;
	int n;
	int m;
	int cost;
};
bool findNot() {
	for (auto it : v) {
		for (auto it2 : it) {
			for (auto it3 : it2) {
				if (it3 == 0)return true;
			}
		}
	}
	return false;
}
int main() {
	SWS;
	cin >> M >> N >> H;
	v.resize(H, vector<vector<int>> (N, vector<int>(M)));
	queue<tomato> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> v[i][j][k];
				if (v[i][j][k] == 1) {
					q.push({ i,j,k,0 });
				}
			}
		}
	}
	while (!q.empty()) {
		tomato f = q.front();
		q.pop();
		vector<tomato> pos = {
			{f.h,f.n + 1,f.m,f.cost + 1},
			{f.h,f.n,f.m + 1,f.cost + 1},
			{f.h,f.n - 1,f.m,f.cost + 1},
			{f.h,f.n,f.m - 1,f.cost + 1},
			{f.h + 1,f.n,f.m,f.cost + 1},
			{f.h - 1,f.n,f.m,f.cost + 1}

		};
		for (auto it : pos) {
			if (
				(
					it.h < 0 || it.h >= H ||
					it.n < 0 || it.n >= N ||
					it.m < 0 || it.m >= M) 
					||
				(
					v[it.h][it.n][it.m] != 0)
				) continue;
			else {
				ans = max(it.cost, ans);
				v[it.h][it.n][it.m] = 1;
				q.push(it);
			}
		}
	}
	cout << (findNot() ? -1 : ans);
	return 0;
}