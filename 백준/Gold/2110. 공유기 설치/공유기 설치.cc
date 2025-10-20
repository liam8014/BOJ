#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define INF 1'000'000'000
using namespace std;
int N, C;
ll maxL, minL = INF,midL,ans;
vector<ll> v;
bool canPos(ll len) {
    int curC = 1;
    for (int i = 0; i < N-1; i++) {
        ll A = v[i];
        bool findNext = false;

        for (int j = i+1; j < N; j++) {
            ll B = v[j];
            if (B - A >= len) {
                curC++;
                i = j-1;
                findNext = true;
                break;
            }
        }

        if (!findNext || curC == C) {
            break;
        }
    }
    return curC >= C;
}
int main() {
    IOS;
    cin >> N >> C;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    maxL = v[N - 1] - v[0];
    for (int i = 1; i < N; i++) {
        minL = min(minL, v[i]-v[i-1]);
    }
    while (maxL - minL > 1) {
        midL = (maxL + minL) / 2;
        
        if (canPos(midL)) {
            minL = midL;
        }
        else {
            maxL = midL;
        }
    }
    if (canPos(maxL)) {
        ans = maxL;
    }
    else if (canPos(midL)) {
        ans = midL;
    }
    else {
        ans = minL;
    }
    
    cout << ans;
    return 0;
}
