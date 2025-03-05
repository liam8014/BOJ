#include <iostream>
#include <queue>
#include <vector>
#define MAXNUM 1000000000
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, ans = MAXNUM;
    cin >> n >> k;
    queue<pair<int, int>> q;
    vector<int> vst(200001,MAXNUM);
    q.push({n,0});
    vst[n] = 0;
    while (!q.empty()) {
        int pos = q.front().first;
        int cost = q.front().second;
        q.pop();
        if (cost >= ans) continue;
        else if (pos >= k) {
            cost += pos - k;
            if (cost < ans) ans = cost;
        }
        else {
            if (vst[pos + 1] > cost + 1) {
                q.push({ pos + 1, cost + 1 });
                vst[pos + 1] = cost + 1;
            }
            if (pos - 1 >= 0 && vst[pos - 1] > cost + 1) {
                q.push({ pos - 1, cost + 1 });
                vst[pos - 1] = cost + 1;
            }
            if (vst[pos * 2] > cost) {
                q.push({ pos * 2, cost });
                vst[pos * 2] = cost;
            }
        }
    }
    cout << ans;
    return 0;
}

