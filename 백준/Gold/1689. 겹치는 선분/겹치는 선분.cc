#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
using namespace std;
int N,ans=0;
int main() {
    IOS;
    cin >> N;
    vector<pii> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        if (!pq.empty() && pq.top() <= v[i].first)
        {
            pq.pop();
        }
        pq.push(v[i].second);
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
    return 0;
}