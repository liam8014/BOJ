#include <iostream>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
using namespace std;
pii dir[4] = { {1,0},{0,1},{0,-1},{-1,0} };
pii hDir[8] = { {2, 1},{-2, 1},{2, -1},{-2, -1},
                    {1,2},{-1,2},{1,-2},{-1,-2} };
struct nd{
    int r, c, w, k;
};
bool v[200][200];
int vst[200][200] = { 0 };
int main() {
    IOS;
    int K,N,M, ans=-1;
    cin >> K >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            v[i][j] = num==1;
        }
    }
    queue<nd> q;
    q.push({ 0,0,0,0 });
    vst[0][0] = true;
    while (!q.empty()) {
        int r = q.front().r, c = q.front().c, w = q.front().w, k = q.front().k;
        if (r == N - 1 && c == M - 1) {
            ans = w;
            break;
        }
        q.pop();
        for (auto d : dir) {
            int nr = r + d.first, nc = c + d.second;
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (v[nr][nc] || vst[nr][nc] & 1 << k) continue;
            vst[nr][nc] |= 1 << k;
            q.push({ nr,nc,w + 1, k});
        }
        if (k >= K)
            continue;
        for (auto d : hDir) {
            int nr = r + d.first, nc = c + d.second;
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (v[nr][nc] || vst[nr][nc] & 1 << (k+1)) continue;
            vst[nr][nc] |= 1 << (k + 1);
            q.push({ nr,nc,w + 1, k+1 });
        }
     }
    cout << ans;
    return 0;
}

