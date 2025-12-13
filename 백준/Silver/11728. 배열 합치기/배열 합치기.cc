#include <iostream>
#include <set>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    IOS;
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        s.insert(num);
    }
    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        s.insert(num);
    }
    for (auto it : s) {
        cout << it << ' ';
    }
    return 0;
}
