#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 500
using namespace std;
int main() {
    IOS;
    int N, M, ans=0;
    cin >> N >> M;
    vector<vector<int>>v(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++) {
        v[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        v[A][B] = 1;
        v[B][A] = -1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (v[i][k] != INF && v[k][j] != INF && v[i][k] * v[k][j] > 0) {
                    v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (v[i][j] == INF)  break;
            if (j == N) ans++;
        }
    }
   cout << ans;
}