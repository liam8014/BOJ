#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int N, M, len=0;
map<string, int> mp; // key : 값, value : 빈도
int main() {
    SWS;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        if(str.length()>=M) mp[str]++;
    }
    vector<pair<string, int>> v;
    for (auto it : mp) {
        v.push_back(it);
    }
    sort(v.begin(), v.end(), [](pair<string, int> p1, pair<string, int> p2) {
        if (p1.second != p2.second) return p1.second > p2.second;
        else return (p1.first.length() == p2.first.length() ? p1.first < p2.first : p1.first.length() > p2.first.length());
        });
    for (auto it : v)
        cout << it.first << '\n';
    return 0;
}