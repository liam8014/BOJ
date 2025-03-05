#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, max_p = 0;
vector<pair<int, int>> v;
vector<int> dp;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    v.resize(n);
    dp.resize(k + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        int w = v[i].first;
        int p = v[i].second;
        for (int j = k; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + p);
        }
    }
    cout << dp[k];
    return 0;
}
