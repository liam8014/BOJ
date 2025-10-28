#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 100000
#define pii pair<int, int>
using namespace std;
int N, M, ans = INF;
vector<vector<bool>> v;
vector<vector<int>> vst;
pii dir[4] = { {1,0},{-1,0} ,{0,1} ,{0,-1} };
struct node{
    int r, c, w;
};
int main() {
    IOS;
    cin >> M >> N;
    v.resize(N, vector<bool>(M));
    vst.resize(N, vector<int>(M,INF));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            v[i][j] = (ch == '1');
        }
    }
    queue<node> q;
    q.push({0,0,0});
    vst[0][0] = 0;
    while (!q.empty()) {
        int r = q.front().r, c = q.front().c, w = q.front().w;
        q.pop();
        for (auto it : dir) {
            int nr = r + it.first, nc = c+ it.second;
            if (nr == N - 1 && nc == M - 1) {
                ans = min(ans, w);
                continue;
            }
            if (nr < 0 || nr >= N || nc < 0 || nc >= M)continue;
            int newWall = (int)v[nr][nc] + w;
            if (vst[nr][nc] <= newWall) continue;
            vst[nr][nc] = newWall;
            q.push({ nr,nc,newWall });
        }
    }
    
    cout << (ans == INF ? 0 : ans);
    return 0;
}