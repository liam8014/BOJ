#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define MAX 2'147'483'648
using namespace std;
struct A {
    int r, c;
};
ll calc(A A1, A A2) {
    return (ll)(A1.r * A1.c * A2.c);
}
int main() {
    IOS;
    int N;
    cin >> N;
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, MAX));
    vector<A> v(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i].r >> v[i].c;
        dp[i][i] = 0;
    }
    for (int len = 1; len < N; len++) {
        
        for (int i = 1; i + len <= N; i++) {
            int j = i + len;
            if (len == 1) {
                dp[i][j] = calc(v[i], v[j]);
            }
            else {
                for(int k=i;k<j;k++)
                dp[i][j] = min (
                    dp[i][k] +  dp[k+1][j] +
                    calc({v[i].r, v[k].c }, {v[k + 1].r, v[j].c}),
                    dp[i][j]
                );
            }
        }
    }
    cout << dp[1][N];
    return 0;
}