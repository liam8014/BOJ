#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PII pair<int,int>
using namespace std;
int sum = 0, N, ans;
vector<int> d;
vector<PII> p;
int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
    IOS;
    cin >> N;
    p.resize(N);
    d.resize(N,0);
    for (int i = 0; i < N;i++) {
        cin >> p[i].first >> p[i].second;
        if (i > 0) {
            d[i] = dist(p[i].first, p[i].second, p[i - 1].first, p[i - 1].second);
            sum += d[i];
        }
    }
    ans = sum;

    for (int i = 1; i < N-1; i++) {
        int tmp = sum - d[i] - d[i + 1] +
            dist(p[i-1].first, p[i-1].second, p[i+1].first, p[i+1].second);
        ans = min(ans, tmp);
    }

    cout << ans;
    return 0;
}