#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    int N,ans =0;
    cin >> N;
    vector<int> v(N);
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        int s = 0, e = N - 1;
        if (e == i) --e;
        else if (s == i) ++s;
        while (s < e) {
            int sum = v[s] + v[e];
            if (sum == v[i]) {
                ans++;
                break;
            }
            else if (sum > v[i]) {
                if (--e == i) --e;
            }
            else {
                if (++s == i) ++s;
            }
        }
    }

    cout << ans;
    return 0;
}