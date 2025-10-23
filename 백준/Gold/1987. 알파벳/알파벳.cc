#include <iostream>
#include <algorithm>
#include <stack>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    SWS;
    int r, c, ans=1;
    struct node {
        int row, col, length, mask;
    };
    char v[20][20];
    const pair<int, int> pos[4] = { {1,0},{-1,0},{0,1},{0,-1} };
    stack<node> stk;
    cin >> r >> c;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> v[i][j];
    stk.push({ 0,0,1, 1 << (v[0][0] - 'A') });
    while (!stk.empty()) {
        node cur = stk.top();
        ans = max(ans, cur.length);
        if (ans == 26) break;
        stk.pop();
        for (auto it : pos) {
            int nr = cur.row + it.first,nc = cur.col + it.second;
            if (nr >= r || nr < 0 ||  nc >= c || nc < 0 ) continue;
            int nbit = 1 << (v[nr][nc] - 'A');
            if (cur.mask & nbit) continue;
            stk.push({ nr,nc,cur.length + 1, cur.mask | nbit });
        }
    }
    cout << ans;
    return 0;
}