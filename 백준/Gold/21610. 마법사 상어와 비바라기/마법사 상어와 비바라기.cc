#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define pii pair<int,int>
using namespace std;
pii dir[8] = { {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };
int N, M;
queue < pii > cld;
vector < vector<int> >v;
struct nextCld {
    int r, c, w;
};
pii move(pii cur, int d, int s) {
    d--;
    int r = cur.first + dir[d].first*s, c = cur.second + dir[d].second*s;
    r += ((abs(r) / N) + 1) * N;
    c += ((abs(c) / N) + 1) * N;
    r = (r - 1) % N;
    c = (c - 1) % N;
    return { r + 1,c + 1 };
}
int water(pii cur) {
    int r = cur.first, c = cur.second, res=0;
    for (int i = 1; i < 8; i += 2) {
        int nr = r + dir[i].first, nc = c + dir[i].second;
        if (nr <= 0 || nc <= 0 || nr > N || nc > N) continue;
        if (!v[nr][nc])continue;
        res++;
    }
    return res;
}
int main() {
    IOS;
    cin >> N >> M;
    v.resize(N+1, vector<int>(N + 1, 0));
    cld.push({ N,1 });
    cld.push({ N,2 });
    cld.push({ N-1,1 });
    cld.push({ N-1,2 });
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> v[i][j];
        }
    }
    while (M--) {
        vector < vector<bool> >vst(N + 1, vector<bool>(N + 1, false));
        queue<nextCld> waters;
        int d, s;
        cin >> d >> s;
        int sz = cld.size();
        for(int i=0;i<cld.size();i++) {
            pii mCld = move(cld.front(), d, s);
            cld.pop();
            v[mCld.first][mCld.second]++;
            vst[mCld.first][mCld.second] = true;
            cld.push(mCld);
        }
        while (!cld.empty()) {
            pii cCld = cld.front();
            waters.push({ cCld.first, cCld.second, water(cCld) });
            cld.pop();
        }
        while (!waters.empty()) {
            v[waters.front().r][waters.front().c] += waters.front().w;
            waters.pop();
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (vst[i][j]) continue;
                if (v[i][j] >= 2) {
                    v[i][j] -= 2;
                    cld.push({ i,j });
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += v[i][j];
        }
    }
    cout << ans;
    return 0;
}