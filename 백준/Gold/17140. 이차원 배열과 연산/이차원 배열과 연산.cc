#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
using namespace std;
int r, c, k;
vector < vector <int> > a(3, vector<int>(3));

void sortV(bool isR, int idx) {
    map<int, int> m;
    vector <int > v;
    if (isR) { //행 연산
        v = a[idx];
        for (int i = 0; i < a[idx].size(); i++) {
            a[idx][i] = 0;
        }
    }
    else {
        for (int i = 0; i < a.size(); i++) {
            v.push_back(a[i][idx]);
            a[i][idx] = 0;
        }
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (auto &it : v) {
        m[it]++;
    }
    for (auto & it : m) {
        if(it.first)
        pq.push({ it.second,it.first });
    }
    if (isR && pq.size()*2 > a[0].size()) { //행 연산이라면? 열번호를 resize해야함
        for (int i = 0; i < a.size(); i++) {
            a[i].resize(min((int)pq.size() * 2, 100), 0);
        }
    }
    if (!isR && pq.size() * 2 > a.size()) { //열 연산이라면? 행번호를 resize해야함
        a.resize( min((int)pq.size() * 2,100) ,vector<int>(a[0].size(),0));
    }
    int idx2 = 0;
    while (!pq.empty() && idx2 < (isR?a[0].size() : a.size())) {
        (isR ? a[idx][idx2++] : a[idx2++][idx]) = pq.top().second;
        (isR ? a[idx][idx2++] : a[idx2++][idx]) = pq.top().first;
        pq.pop();
    }
}
int main() {
    int t=0;
    cin >> r >> c >> k;
    r--, c--;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            cin >> a[i][j];
        }
    }
    while (t <= 100) {
        if (r < a.size() && c < a[0].size() && a[r][c] == k)  {
            break;
        }

        if (a.size() >= a[0].size()) { //행 연산
            for (int i = 0; i < a.size(); i++) {
                sortV(true, i);
            }
        }
        else {
            for (int i = 0; i < a[0].size(); i++) {
                sortV(false, i);
            }
        }

     t++;
    }

    cout << (t > 100 ? -1 : t);
    return 0;
}