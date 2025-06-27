#include <iostream>
#include <algorithm>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    int N,ans=0; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
        ans = max(ans, v[i] * (N - i));
    cout << ans;
    return 0;
}