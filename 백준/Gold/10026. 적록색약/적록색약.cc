#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> v;
vector<vector<char>> v2;
vector<vector<bool>> vst;
vector<vector<bool>> vst2;
int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ans1=0, ans2 = 0;
    cin >> n;
    v.resize(n, vector<char>(n));
    vst.resize(n, vector<bool>(n,false));
    v2.resize(n, vector<char>(n));
    vst2.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n;j++) {
            cin >> v[i][j];
            v2[i][j] = (v[i][j] == 'G' ? 'R' : v[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vst[i][j]&&vst2[i][j])continue;
  
            if(!vst[i][j]) {
                queue<pair<int, int>> q;
                char color = v[i][j];
                q.push({ i, j });
                vst[i][j] = true;
                ans1++;
                while (!q.empty()) {
                    int ci = q.front().first;
                    int cj = q.front().second;
                    q.pop();
                    vector< pair<int, int> > dir = { {ci + 1,cj}, {ci,cj + 1}, {ci - 1,cj}, {ci,cj - 1} };
                    for (auto it : dir) {
                        int ni = it.first, nj = it.second;
                        if ((ni < 0 || ni >= n) || (nj < 0 || nj >= n)) continue;
                        if (vst[ni][nj])continue;
                        char ncolor = v[ni][nj];
                        if (color != ncolor) continue;

                        q.push({ ni,nj });
                        vst[ni][nj] = true;
                    }
                }
            }  

            if (!vst2[i][j]) {
                queue<pair<int, int>> q;
                char color = v2[i][j];
                q.push({ i, j });
                vst2[i][j] = true;
                ans2++;
                while (!q.empty()) {
                    int ci = q.front().first;
                    int cj = q.front().second;
                    q.pop();
                    vector< pair<int, int> > dir = { {ci + 1,cj}, {ci,cj + 1}, {ci - 1,cj}, {ci,cj - 1} };
                    for (auto it : dir) {
                        int ni = it.first, nj = it.second;
                        if ((ni < 0 || ni >= n) || (nj < 0 || nj >= n)) continue;
                        if (vst2[ni][nj])continue;
                        char ncolor = v2[ni][nj];
                        if (color != ncolor) continue;

                        q.push({ ni,nj });
                        vst2[ni][nj] = true;
                    }
                }
            }
        }
    }
    std::cout << ans1 << ' ' << ans2;
    return 0;
}