#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<vector<int>> order;
int D[1001] = { 0 };
bool vst[1001] = { false };
void update(int W) {
    vst[W] = true;
    int worstD = 0;
    if (order[W].size() == 1) return;
    for (auto it : order[W]) {
        if (!vst[it]) {
            update(it);
        }
        if (vst[it]) {
            if(it != W) {
                worstD = max(worstD, D[it]);
            }
        }
    }
    D[W] += worstD;
}
int main()
{
    IOS;
    int T;
    cin >> T;
    while (T--) {
        int N, K, W;
        cin >> N >> K;
        order.clear();
        order.resize(N+1);
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
            vst[i] = false;
            order[i].push_back(i);
        }
        while (K--) {
            int X, Y;
            cin >> X >> Y;
            order[Y].push_back(X);
        }
        cin >> W;
        update(W);
        cout << D[W] << '\n';
    }
    return 0;
}