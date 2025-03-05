#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void pv(vector <vector <int>> v) {
    for (auto it1 : v) {
        for (auto it2 : it1) { cout << it2 << " "; }
        cout << '\n';
    }
}
int f(vector <vector <int>> v) {
    queue<pair<int, int>> next;
    int day = 0, nCnt=0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 1) { next.push(make_pair(i, j)); }
            else if (v[i][j] == 0) { nCnt++; }
        }
    }
    if (nCnt == 0) { return 0; }
    do {
        //pv(v);
        //cout << "day : " << day << "\n\n\n";

        if (next.empty()) return -1;
        int sz = next.size();
        for (int idx = 0; idx<sz; idx++) {
            int i = next.front().first;
            int j = next.front().second;
            if (j + 1 < v[i].size() && v[i][j + 1] == 0) {
                v[i][j + 1] = 1;
                nCnt--;
                next.push(make_pair(i, j + 1));
            }
            if (i + 1 < v.size() && v[i+1][j] == 0) {
                v[i+1][j] = 1;
                nCnt--;
                next.push(make_pair(i+1, j));
            }
            if (j - 1 >= 0 && v[i][j - 1] == 0) {
                v[i][j - 1] = 1;
                nCnt--;
                next.push(make_pair(i, j - 1));
            }
            if (i - 1 >= 0 && v[i - 1][j] == 0) {
                v[i-1][j] = 1;
                nCnt--;
                next.push(make_pair(i-1, j));
            }
            next.pop();
        }
        day++;
    } while (nCnt > 0);
    return day;
}
int main() {
    int m, n;
    cin >> m >> n; // 토마토 박스의 크기를 입력음
    vector <vector <int>> v(n);
    for (int i = 0; i < n; i++) {
        vector <int> tmp(m);
        for (int j = 0; j < m; j++) {
            cin >> tmp[j];
        }
        v[i] = tmp;
    }
    cout << f(v);
    return 0;
}
