#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ans=-1000;
    cin >> n;
    vector<int> v(n), dp(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    dp[0] = v[0];
    ans = max(ans, dp[0]);
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + v[i], v[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}