#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    int N, S, s = 0, e = 1, ans;
    cin >> N >> S;
    vector<int> v(N+1);
    ans = N + 1;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    if(ans!=1)
        while (true) {
            int cur = v[e] - v[s];
            if (cur >= S) {
                ans = min(ans, e - s);
                s++;
            }
            else if (cur < S || s >= e - 1) e++;
            if (e > N && cur <= S) break;
        }
    cout << (ans > N ? 0 : ans);
    return 0;
}