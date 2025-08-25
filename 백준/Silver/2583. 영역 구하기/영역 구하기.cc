#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
using namespace std;
int M, N, K;
pii dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
vector <vector<bool>> v;
vector<int> areas;
int main() {
    IOS;
    cin >> M >> N >> K;
    v.resize(M, vector<bool>(N,false));
    while (K--) {
        int m1, n1, m2, n2;
        cin >> n1 >> m1 >> n2 >> m2;
        n2--, m2--;
        for (int i = m1; i <= m2; i++) {
            for (int j = n1; j <= n2; j++) {
                v[i][j] = true;
            }
        }
    }
   
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j]) continue;
            queue<pii> q;
            q.push({ i,j });
            v[i][j] = true;
            int area = 0;
            while (!q.empty()) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                area++;
                for (auto it : dir) {
                    int nr = r + it.first, nc = c + it.second;
                    if (nr < 0 || nc < 0 || nr >= M || nc >= N) continue;
                    if (v[nr][nc]) continue;
                    v[nr][nc] = true;
                    q.push({ nr,nc });
                }
            }
            areas.push_back(area);
        }
    }
    cout << areas.size() <<'\n';
    sort(areas.begin(), areas.end());
    for (auto it : areas) {
        cout << it << ' ';
    }
    return 0;
}