#include <iostream>
#include <vector>
#include <algorithm>

#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    SWS;
    int n;
    cin >> n;

    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) 
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }

    cout << dp[n] << endl;
    return 0;
}