#include <iostream>
#include <vector>
#include <algorithm>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int n,ans=0;
vector<int>v;
vector<pair<int,int>>memo;
void func(int idx, int streak, int sum) {
    sum += v[idx];
    if (idx == n) {
        ans = max(sum, ans);
    }
    else {
        if (memo[idx].first >= sum && memo[idx].second <= streak ) return;
        else {
            memo[idx].first = sum;
            memo[idx].second = streak;
        }
        if (streak < 1) func(idx+1, streak + 1, sum);
        if(idx+2<=n) func(idx+2, 0, sum);
    }
}

int main() {
    SWS;

    cin >> n;
    v.resize(n+1);
    memo.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    func(0, -1, 0);
    cout << ans;
    return 0;
}