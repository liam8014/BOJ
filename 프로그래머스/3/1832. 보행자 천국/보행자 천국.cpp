#include <vector>
#include <cstring>

using namespace std;

const int MOD = 20170805;
int n, m;
vector<vector<int>> v;

int dp[500][500][2]; 

int dfs(int r, int c, int d) {
    if (r == n - 1 && c == m - 1) return 1;

    if (d != -1 && dp[r][c][d] != -1) return dp[r][c][d];

    int paths = 0;
    
    for (int i = 0; i < 2; i++) {
        int nr = r + (i == 1 ? 1 : 0);
        int nc = c + (i == 0 ? 1 : 0);

        if (nr >= n || nc >= m || v[nr][nc] == 1) continue;
        if (v[r][c] == 2 && d != -1 && d != i) continue;

        paths = (paths + dfs(nr, nc, i)) % MOD; 
    }

    if (d != -1) dp[r][c][d] = paths;
    
    return paths;
}

int solution(int _n, int _m, vector<vector<int>> _v) {
    n = _n; m = _m; v = move(_v);
    
    memset(dp, -1, sizeof(dp)); 
    
    return dfs(0, 0, -1);
}