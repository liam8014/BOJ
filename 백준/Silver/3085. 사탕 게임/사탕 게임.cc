#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
vector<vector<char>> board;
int check() {
    int ret = 1;

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (board[i][j] == board[i][j - 1]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            ret = max(ret, cnt);
        }
    }
    for (int j = 0; j < n; j++) {
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (board[i][j] == board[i - 1][j]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            ret = max(ret, cnt);
        }
    }

    return ret;
}

int main() {
    IOS;

    cin >> n;
    board.resize(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 < n) {
                swap(board[i][j], board[i][j + 1]);
                ans = max(ans, check());
                swap(board[i][j], board[i][j + 1]);
            }
            if (i + 1 < n) {
                swap(board[i][j], board[i + 1][j]);
                ans = max(ans, check());
                swap(board[i][j], board[i + 1][j]);
            }
        }
    }

    cout << ans;
    return 0;
}
