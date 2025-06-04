#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    IOS;
    int N , ans=0,X;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    cin >> X;
    sort(v.begin(), v.end());
    int s = 0, e = N-1;
    while (s != e) {
        int cur = v[s] + v[e];
        if (cur > X) {
            e--;
        }
        else if (cur < X) {
            s++;
        }
        else if (cur == X) {
            e--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
