#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    SWS;
    int n, ans=1;
    set <string> d;
    cin >> n;
    d.insert("ChongChong");
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        bool findA = find(d.begin(), d.end(), a) != d.end(), findB = find(d.begin(), d.end(), b) != d.end();
        if (findA&&!findB) {
            d.insert(b);
            ans++;
        }
        else if (findB && !findA) {
            d.insert(a);
            ans++;
        }
    }
    cout << ans;
    return 0;
}