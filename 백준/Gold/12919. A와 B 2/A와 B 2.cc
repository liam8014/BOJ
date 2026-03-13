#include <iostream>
#include <string>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string S, T;
bool found = false;
void solve(string cur) {
    if (found) return;
    if (cur.length() == S.length()) {
        if (cur == S) found = true;
        return;
    }

    if (cur.back() == 'A') {
        string next = cur;
        next.pop_back();
        solve(next);
    }

    if (found) return;

    if (cur.front() == 'B') {
        string next = cur;
        reverse(next.begin(), next.end());
        next.pop_back();
        solve(next);
    }
}

int main() {
    IOS;
    cin >> S >> T;

    solve(T);

    cout << (found ? 1 : 0);
    return 0;
}