#include <iostream>
#include <algorithm>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PII pair<int,int>
using namespace std;

int C, N;
vector<PII> v;

int main() {
    IOS;
    cin >> C >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;

    // DP 로직 시작
    const int INF = 1000000000;
    vector<int> dp(C + 1, INF);
    dp[0] = 0;

    // 각 도시를 무한히 사용할 수 있는 무한 배낭
    for (int i = 0; i < N; i++) {
        int cost = v[i].first;
        int cust = v[i].second;
        for (int j = 0; j <= C; j++) {
            if (dp[j] == INF) continue;
            int nj = min(C, j + cust);
            dp[nj] = min(dp[nj], dp[j] + cost);
        }
    }

    // 최소 비용 출력
    cout << dp[C];
    return 0;
}
