#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
vector<int> v;
int stick(int len) {
    int res = 0;
    if (len == 0)
        return 0;
    for (auto it : v) {
        res += it / len;
    }
    return res;
}
int main() {
    IOS;
    cin >> n >> m;
    int left = 1, right=0;
    v.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        right = max(right, v[i]);
    }
    int mid = 0;

    while (right - left > 1) {
        mid = (left + right) / 2;
        int stk = stick(mid);
        if (stk >= n) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    int ans = 0;
    if (stick(right) >= n) {
        ans = right;
    }
    else if (stick(mid) >= n) {
        ans = mid;
    }
    else if(stick(left) >= n){
        ans = left;
    }
    cout << ans;
    return 0;
}
