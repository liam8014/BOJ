#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int N, ans = 0;
struct node {
    int r, c, f;
};
node pos[3] = { {0, 1} ,{1, 1} ,{1, 0} };
stack<int> s_vst;
vector<vector<int>> v;
bool isInval(int r,int c) {
    return ((r >= N || r < 0) || (c >= N || c < 0) || v[r][c]);
}
void dfs(node nd) {
    if (nd.r == N - 1 && nd.c == N - 1) ans++;
    else {
        s_vst.push(nd.f);
        for (int i = 0; i < 3; i++) {
            if ((nd.f == 0 && i == 2) || (nd.f == 2 && i == 0)) continue;

            int r2 = nd.r + pos[i].r, c2 = nd.c + pos[i].c;
            if (isInval(r2,c2)) continue;
            if (i == 1 && (isInval(r2 - 1, c2) || isInval(r2, c2-1))) continue;
            dfs({ r2,c2,i });
        }
        s_vst.pop();
    }
}

int main() {
    SWS;
    cin >> N;
    v.resize(N, vector<int> (N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> v[i][j];
    dfs({ 0, 1, 0});
    cout << ans;
    return 0;
}