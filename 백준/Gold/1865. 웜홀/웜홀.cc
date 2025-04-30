#include <iostream>
#include <vector>
#include <algorithm>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1000000000
using namespace std;
vector<vector<long long>> v;
int N, M, W;

int main() {
    SWS;
    int TC; cin >> TC;
    while (TC--)
    {
        cin >> N >> M >> W;
        v.clear();
        v.resize(N + 1, vector<long long>(N + 1, INF));
        for (int i = 1; i <= N; i++) v[i][i] = 0;

        for (int i = 0; i < M; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            v[S][E] = min(v[S][E], (long long)T);
            v[E][S] = min(v[E][S], (long long)T);
        }

        for (int i = 0; i < W; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            v[S][E] = min(v[S][E], (long long)-T);
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (v[i][k] != INF && v[k][j] != INF) {
                        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                    }
                }
            }
        }

        bool ans = false;
        for (int i = 1; i <= N; i++) {
            if (v[i][i] < 0) {
                ans = true;
                break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}