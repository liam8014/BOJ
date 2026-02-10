#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 150000
using namespace std;
pii dir[4] = { {0,1},{1,0},{-1,0},{0,-1} };
struct node {
    int r, c,w;

};
bool operator <(node n1, node n2) {
    return n1.w > n2.w;
}
int main() {
    IOS;
    int T = 1;
    while (true) {
        int N;
        cin >> N;
		if (N == 0) break;
        vector<vector<int>> v(N, vector<int>(N));
        vector<vector<int>> vst(N, vector<int>(N,INF));
        priority_queue<node> pq;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> v[i][j];
            }
        }
        vst[0][0] = v[0][0];
        pq.push({ 0,0,v[0][0] });
        while (!pq.empty()) {
            int r = pq.top().r, c = pq.top().c, w = pq.top().w;
            pq.pop();
            vst[r][c] = w;
            if (r == N - 1 && c == N - 1) break;
            for (auto d : dir) {
                int nr = r + d.first, nc = c +  d.second;
                if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                if (vst[nr][nc] <= v[nr][nc] + w) continue;
                pq.push({ nr,nc,v[nr][nc] + w });
            }
        }

        cout << "Problem " << T++ <<": " << vst[N - 1][N - 1] << '\n';
    }
    
    return 0;
}