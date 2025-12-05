#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 100'000'000
using namespace std;
int main() {
    IOS;
    int n,sz, ans = INF;
    cin >> n;
    sz = 1 << n;
    vector<vector<int>> v(n,vector<int>(n)), dp(sz,vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           cin >> v[i][j];
        }
    }
    dp[1][0] = 0;
    for (int m = 0; m < sz; m++) {
        for (int c = 0; c < n; c++) {
            for (int x = 0; x < n; x++) { 
                if(m & (1 << x)) continue;
                if (v[c][x] == 0) continue;
                if (dp[m][c] == INF) continue;
                int nm = m | (1 << x);
                dp[nm][x] = min(dp[nm][x], dp[m][c] + v[c][x]);
            }
        }
    }
    for (int c = 1; c < n; c++) {
        if (dp[sz - 1][c] == INF) continue;
        if (v[c][0] == 0) continue;
        ans = min(ans, dp[sz - 1][c] + v[c][0]);
    }
    cout << ans;
    return 0;
}
