#include <iostream>
#include <map>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    map<int, int> x,y;
    for (int i = 0; i < 3;i++) {
        int a, b;
        cin >> a >> b;
        x[a]++;
        y[b]++;
    }

    for (auto it : x) {
        if (it.second < 2) {
            cout << it.first << ' ';
            break;
        }
    }
    for (auto it : y) {
        if (it.second < 2) {
            cout << it.first << ' ';
            break;
        }
    }
    return 0;
}