#include <iostream>
#include <vector>
#include <list>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PII pair<int,int>
using namespace std;
PII dir[8] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1} };
struct node {
    int r, c, w;
};
int main() {
    IOS;
    int N, M, K, tree=0;
    cin >> N >> M >> K;
    vector<vector<int>> A(N + 1, vector<int>(N + 1)) ,B(N+1,vector<int>(N+1,5));
    vector<vector<list<int>>> v(N+1,vector<list<int>>(N+1));
    list<PII> TL;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    while (M--) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x][y].push_back(z);
        TL.push_back({ x, y });
    }
    while (K--) {
        vector<node> dead, repro;
        //봄
        for (auto t = TL.begin(); t!=TL.end();) {
            int i = t->first, j = t->second;
            if (v[i][j].empty()) continue;
            for (auto it = v[i][j].begin(); it != v[i][j].end();) {
                if (*it <= B[i][j]) {
                    B[i][j] -= *it;
                    (*it) += 1;
                    if (*it % 5 == 0) {
                        if (!repro.empty() && repro.back().r == i && repro.back().c == j) {
                            repro.back().w += 1;
                        }
                        else {
                            repro.push_back({ i,j,1 });
                        }
                    }
                    it++;
                }
                else {
                    dead.push_back({ i, j, *it / 2 });
                    it = v[i][j].erase(it);
                }
            }
            if (v[i][j].empty()) {
                t = TL.erase(t);
            }
            else {
                t++;
            }
        }
        //여름
        for (auto it : dead) {
            B[it.r][it.c] += it.w;
        }
        //가을
        for (auto it : repro) {
            int r = it.r, c = it.c;
            for (auto d : dir) {
                int nr = r + d.first, nc = c + d.second;
                if (nr <= 0 || nc <= 0 || nr > N || nc > N)continue;
                if (v[nr][nc].size() == 0) {
                    TL.push_back({ nr,nc });
                }
                for(int i =0;i<it.w;i++) {
                    v[nr][nc].push_front(1);
                }
            }
        }
        //겨울
        tree = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                B[i][j] += A[i][j];

                tree += v[i][j].size();
            }
        }
    }
    cout << tree;
    return 0;
}