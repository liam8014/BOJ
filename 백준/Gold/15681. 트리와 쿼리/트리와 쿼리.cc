#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 100001
using namespace std;
vector<bool> vst;
vector<vector<int>> v;
vector<int> dp;
int N, R, Q;
void func(int cur, int prt) {
    bool find = false;
    for (const auto& it : v[cur]) {
        if (!vst[it]) {
            find = true;
            vst[it] = true;
            func(it, cur);
        }
    }
    dp[prt] += dp[cur];
}
int main() {
    IOS;
    cin >> N >> R >> Q;
    vst.resize(N + 1, false);
    vst[R] = true;
    v.resize(N + 1);
    dp.resize(N + 1, 1);
    for (int i = 0; i < N-1; i++) {
        int U, V;
        cin >> U >> V;
        v[U].push_back(V);
        v[V].push_back(U);
    }
    func(R, 0);
    while (Q--) {
        int num;
        cin >> num;
        cout << dp[num] << '\n';
    }
    return 0;
}