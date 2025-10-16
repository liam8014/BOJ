#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define INF 2000000000
using namespace std;

int n;
int main() {
    IOS;
    cin >> n;
    ll gap = (ll)INF, A = 0, B = 0;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());


    // lower_bound 기반 수정: 각 i에 대해 j > i 인 범위에서 탐색
    for (int i = 0; i < n - 1; ++i) {
        ll a = v[i];
        // 핵심: 검색 범위를 i+1부터 끝까지로 제한 (자기 자신 선택 방지 & 경계 안전)
        auto it = lower_bound(v.begin() + i + 1, v.end(), -a);

        // it 가 유효한 경우 (it != end) 후보 검사
        if (it != v.end()) {
            ll sum = a + *it;
            if (llabs(sum) < gap) {
                gap = llabs(sum);
                A = a; B = *it;
            }
        }

        // it 이전 원소도 후보가 될 수 있으므로 it-1 검사 (it가 처음 위치가 아니라면)
        if (it != v.begin() + i + 1) {
            auto it2 = it;
            --it2; // 안전: it2 >= v.begin()+i+1
            ll sum = a + *it2;
            if (llabs(sum) < gap) {
                gap = llabs(sum);
                A = a; B = *it2;
            }
        }
    }

    if (A > B) swap(A, B);
    cout << A << ' ' << B;
    return 0;
}
