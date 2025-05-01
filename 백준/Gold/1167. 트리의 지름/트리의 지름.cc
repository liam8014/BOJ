#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct node {
    vector<pair<int,int>> childs;
};
int vst[100001] = {false};
stack<pair<int, int>>stk; //first : 탐색된 노드, second : 현재까지의 가중치
vector<node> v; //노드들의 정보
int n, ans = 0, oppo_nd = 0;
void dfs(int nd) {
    vst[nd] = true;
    bool updated = false;
    for (auto it : v[nd].childs) {
        int c = it.first, a = it.second;
        if (!vst[c]) {
            stk.push({
                nd,
                (stk.empty() ? a : stk.top().second + a)
             });
            dfs(c);
            stk.pop();
            updated = true;
        }
    }

    if (!updated && stk.top().second > ans) {
        ans = stk.top().second;
        oppo_nd = nd;
    }
    vst[nd] = false;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int p, c = 0, a;//부모, 자식, 가중치
        cin >> p;
        while (true) {
            cin >> c;
            if (c == -1) break;
            cin >> a;
            v[p].childs.push_back({ c,a });
        }
    }
    dfs(1);
    dfs(oppo_nd);
    cout << ans;
    return 0;
}