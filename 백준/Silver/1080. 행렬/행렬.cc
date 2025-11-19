#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
    IOS;
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> A(N, vector<bool>(M)), B(N, vector<bool>(M));
    char ch;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ch;
            A[i][j] = (ch == '1');
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ch;
            B[i][j] = (ch == '1');
        }
    }

    if (N < 3 || M < 3) {
        if (A == B) cout << 0;
        else cout << -1;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {
            if (A[i][j] != B[i][j]) {
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        A[x][y] = !A[x][y];
                    }
                }
                ans++;
            }
        }
    }

    if (A == B) cout << ans;
    else cout << -1;

    return 0;
}
