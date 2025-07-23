#include <iostream>
#include <stack>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

static int L[1000001], R[1000001];

int main() {
    IOS;
    int x, root = 0;
    while (cin >> x) {
        if (root == 0) {
            root = x;
        }
        else {
            int cur = root;
            while (true) {
                if (x < cur) {
                    if (L[cur] == 0) { L[cur] = x; break; }
                    cur = L[cur];
                }
                else {
                    if (R[cur] == 0) { R[cur] = x; break; }
                    cur = R[cur];
                }
            }
        }
    }

    // 스택 두 개를 이용한 후위 순회
    stack<int> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        int u = s1.top(); s1.pop();
        s2.push(u);
        if (L[u]) s1.push(L[u]);
        if (R[u]) s1.push(R[u]);
    }
    while (!s2.empty()) {
        cout << s2.top() << '\n';
        s2.pop();
    }
    return 0;
}
