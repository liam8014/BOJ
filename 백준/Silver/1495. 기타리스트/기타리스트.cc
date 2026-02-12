#include <iostream>
#include <vector>
#include <set>
#define ll long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N, S, M;
int main() {
    cin >> N >> S >> M;
    set<int> dp[51];
    dp[0].insert(S);
    for (int i = 1; i <= N; i++) {
        int volAmt; cin >> volAmt;
        for (const auto& d : dp[i - 1]) {
            if (d+volAmt <=M) {
                dp[i].insert(d + volAmt);
            }
            if (d - volAmt >= 0) {
                dp[i].insert(d - volAmt);
            }
        }
    }
    if(!dp[N].empty()) cout << *(--dp[N].end());
    else cout << -1;
    return 0;
}