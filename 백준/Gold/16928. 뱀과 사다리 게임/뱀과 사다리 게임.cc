#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1000
using namespace std;
int main() {
	SWS;
	int N, M;
	cin >> N >> M;
	vector<int> v(101,0); // 이동 위치
	vector<int> ans(101, INF); //최소 코스트
	queue<pair<int, int>> q; //현재 위치, 현재까지 코스트 
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a] = b;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a] = b;
	}

	q.push({ 1, 0 });
	ans[1] = 0;
	while (!q.empty()) {
		int pos = q.front().first, cost = q.front().second;
		q.pop();
		for (int i = 1; (i <= 6 && pos + i <= 100 ); i++) {
			int npos = pos + i;
			if (v[npos] != 0)
			{
				npos = v[npos];
			}

			if (cost+1 < ans[npos]) {
				ans[npos] = cost + 1;
				q.push({ npos, cost + 1 });
			}
		}
	}
	std::cout << ans[100];
}