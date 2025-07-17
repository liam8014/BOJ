#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    map<string, bool> m;
    int n; cin >> n;
    vector<pair<string, bool>> v(n);
    for (int i = 0; i < n; i++) {
        string name, cmd;
        cin >> name >> cmd;
        m[name] = (cmd == "enter");
    }
    copy(m.begin(), m.end(), v.begin());
    reverse(v.begin(), v.end());
    for (auto it : v)
        if (it.second)
            cout << it.first <<'\n';
    return 0;
}