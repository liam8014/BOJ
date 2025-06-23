#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
struct node{
    int r, c, d;
} nd;
int N, M, ans = 0;
vector<vector<int>> v;
pair<int, int> dir[4] = { {-1,0}, {0,1},{1,0},{0,-1} };
bool doClean() {  
    if (!v[nd.r][nd.c]) {
        v[nd.r][nd.c] = 2; //2가 청소된 상태
        ans++;
    }
    bool isFound = false;
    int _d;
    for (int d = nd.d - 1, i = 0; i<4; i++,d--) {
        if (d == -1) d = 3;
        int _r = nd.r + dir[d].first, _c = nd.c + dir[d].second;
        if (_r < 0 || _r >= N || _c < 0 || _c >= M) continue;
        if (v[_r][_c] == 0) {
            _d = d; //새로운 방향
            isFound = true;
            break;
        }
     }
    if (isFound) {
        nd.r += dir[_d].first;
        nd.c += dir[_d].second;
        nd.d = _d;
        return true;
    }
    else {
        pair<int, int> back = { dir[nd.d].first * (-1), dir[nd.d].second * (-1) }; //후진 방향
        int _r = nd.r + back.first, _c = nd.c + back.second;
        if (_r < 0 || _r >= N || _c < 0 || _c >= M) return false;
        if (v[_r][_c] == 1) return false;

        nd.r = _r, nd.c = _c;
        return true;
    }
}
int main() {
    IOS;

    cin >> N >> M;
    v.resize(N, vector<int>(M));
    cin >> nd.r >> nd.c >> nd.d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> v[i][j];

    while (doClean());
    cout << ans;
    return 0;
}
