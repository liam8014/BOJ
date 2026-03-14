#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    IOS;
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> dp(N+1,vector<int>(4,0)); 
        dp[1][1] = 1;
        if(N>=2) {
            dp[2][1] = 1;
            dp[2][2] = 1;
        }
        if(N>=3) {
            dp[3][1] = 1;
            dp[3][2] = 1;
            dp[3][3] = 1;
        }
        for (int i = 4; i <= N; i++) {
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-2][1] + dp[i-2][2];
            dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
        }
        cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';
    }

    return 0;
}