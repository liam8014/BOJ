#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ULL unsigned long long
#define MOD 1000000000
using namespace std;

int main() {
    IOS;
    int n; cin >> n;
    ULL ans = 0;
    vector<vector<ULL>> dp(n+1, vector<ULL>(10));
    for (int i = 1; i <= 9; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            switch (j)
            {
            case 0:
                dp[i][j] = dp[i-1][1];
                break;
            case 9:
                dp[i][j] = dp[i - 1][8];
                break;
            default:
                dp[i][j] = dp[i - 1][j-1] + dp[i - 1][j + 1];
                break;
            }
            dp[i][j] %= MOD;
        }
    }
    int num = 0;
    for (auto it : dp[n])
    {
        ans += it;
        ans %= MOD;
    }

    cout << ans;
    return 0;
}