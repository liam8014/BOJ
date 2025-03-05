#include <iostream>
#include <vector>
#include <cmath>
#define INF 10000000
using namespace std;
vector<pair<int, int>>house;
vector<pair<int, int>>chicken;
int n, m, ans = INF;
int searchNear(pair<int, int> &p, vector<pair<int, int>>& vp) {
    int fr = p.first, fc = p.second, res=INF;
    for (int i = 0; i < vp.size(); i++) {
        int newRes = abs(vp[i].first - fr) + abs(vp[i].second - fc);
        if (newRes < res) res = newRes;
    }
    return res;
}
int getDistSum(vector<pair<int, int>>& vp) {
    int res = 0;
    for (int i = 0; i < house.size(); i++) {
        res+=searchNear(house[i], vp);
    }
    return res;
}
void BT(vector<pair<int, int>> vp, int idx) {
    if (vp.size() == m) {
        int newAns = getDistSum(vp);
        if (ans > newAns) ans = newAns;
    }
    else {
        if ((chicken.size() - idx) + vp.size() >= m) {//남은 치킨 집의 개수 + 선택한 치킨집의 개수 >= m 이어야함!
            if((idx + 1 <= chicken.size()))  {
                BT(vp, idx + 1);

                vp.push_back(chicken[idx]);
                BT(vp, idx + 1);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            switch (input) {
                case 1:
                    house.push_back({ i,j });
                    break;
                case 2 : 
                    chicken.push_back({ i,j });
                    break;
            };
        }
    }
    vector<pair<int, int>> vp;
    BT(vp, 0);
    cout << ans;

    return 0;
}