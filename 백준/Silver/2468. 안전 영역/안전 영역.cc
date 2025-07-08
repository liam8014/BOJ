#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PII pair<int,int>
using namespace std;
vector<vector<int>> v,v_init;
queue<PII> q;
PII dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };
int n, ans = 0;
void rain(int h) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] <= h || v[i][j]==0) continue;
            v[i][j] = 0;
            sum++;
            q.push({ i, j });
            while (!q.empty()) {
                for (auto it : dir) {
                    int ni = q.front().first + it.first, nj = q.front().second + it.second;
                    if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                    if (v[ni][nj] == 0 || v[ni][nj] <= h) continue;
                    v[ni][nj] = 0;
                    q.push({ ni,nj });
                }
                q.pop();
            }
        }
    }
    ans = max(ans, sum);
}

int main() {
    IOS;
    int maxH = 0;
    cin >> n;
    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            maxH = max(v[i][j], maxH);
        }
            
    v_init = v;
    for (int h = 0; h < maxH; h++) {
        v = v_init;
        rain(h);
    }
    cout << ans;
    return 0;
}