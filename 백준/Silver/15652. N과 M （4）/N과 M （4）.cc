#include <iostream>
#include <vector>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int n, m;
vector<int> v;
void dfs(int num) {
    v.push_back(num);
    if (v.size() == m) {
        for (auto it : v)
            cout << it << ' ';
        cout << '\n';
    }
    else {
        for (int i = v.back(); i <= n; i++)
            dfs(i);
    }
    v.pop_back();
}
int main() {
    SWS;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dfs(i);
    return 0;
}