#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
using namespace std;
int main() {
    IOS;
    int N;
    ll ans = 0;
    cin >> N;
    vector<int> A(N), B(N), C(N), D(N);
    vector<int> AB, CD;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int ab = A[i] + B[j],
                cd = C[i] + D[j];
            AB.push_back(ab);
            CD.push_back(cd);
        }
    }
    sort(CD.begin(), CD.end());
    for (auto ab : AB) {
        auto res = equal_range(CD.begin(), CD.end(), -ab);
        ans += (ll)(res.second - res.first);
    }
    cout << ans;
    return 0;
}