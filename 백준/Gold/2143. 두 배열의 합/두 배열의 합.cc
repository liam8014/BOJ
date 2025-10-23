#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
using namespace std;
ll T, n, m, ans = 0;
unordered_map<ll, ll> um;
vector<ll> A, B, AC, BC,
ASum, BSum;

int main() {
    IOS;
    cin >> T;

    cin >> n;
    A.resize(n+1);
    AC.resize(n+1,0);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        AC[i] = AC[i - 1] + A[i];
    }

    cin >> m;
    B.resize(m+1);
    BC.resize(m+1,0);
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
        BC[i] = BC[i - 1] + B[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ASum.push_back(AC[j] - AC[i - 1]);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            BSum.push_back(BC[j] - BC[i - 1]);
        }
    }
    sort(BSum.begin(), BSum.end());

    for (auto as : ASum) {
        ll T2 = T - as;
        int cnt = 0;
        auto lb = lower_bound(BSum.begin(), BSum.end(), T2);
        if (um[T2] > 0) {
            ans += um[T2];
            continue;
        }
        while (lb != BSum.end() && T2 ==*lb++) {
            cnt++;
        }
        um[T2] = cnt;
        ans += cnt;
    }

    cout << ans;
    return 0;
}
