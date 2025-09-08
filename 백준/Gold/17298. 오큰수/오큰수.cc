#include <iostream>
#include <stack>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
using namespace std;
int main() {
    IOS;
    int N; cin >> N;
    stack<pii>s;
    vector<int> v,ans(N);
    while (N--) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    s.push({ 0,v[0] });
    for (int i = 1; i < v.size();i++) {
        int nxt = -1;
        if (i < v.size()) nxt = v[i];
        while (!s.empty() && nxt > s.top().second) {
            ans[s.top().first] = nxt;
            s.pop();
        }
        s.push({ i,v[i] });
    }
    while (!s.empty()) {
        ans[s.top().first] = -1;
        s.pop();
    }
    for (auto it : ans)
        cout << it << ' ';
    return 0;
}