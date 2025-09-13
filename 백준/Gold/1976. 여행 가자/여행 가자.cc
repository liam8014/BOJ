#include <iostream>
#include <vector>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N, M;
int trip[1001];
bool can[201][201]= {false};
bool vst[201][201] = { false };
vector<vector<int>> v;
int main() {
    IOS;
    cin >> N >> M;
    v.resize(N+1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int b; cin >> b;
            if (can[i][j]) continue;
            if (i == j) 
            {
                can[i][j] = true;
                vst[i][j] = true;
            }
            else if(b == 1)
            {
                can[i][j] = true;
                can[j][i] = true;
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int frt = q.front();
            q.pop();
            for (auto it : v[frt]) {
                if (vst[i][it]) continue;
                can[it][i] = can[i][it] = true;
                vst[i][it] = true;
                q.push(it);
            }
        }
    }

    bool ans = true;
    for (int i = 0; i < M; i++) {
        cin >> trip[i];
        if (i > 0 && ans) {
            ans = can[trip[i - 1]][trip[i]];
        }
    }
    cout << (ans ? "YES" : "NO");
    return 0;
}