#include <iostream>
#include <queue>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    priority_queue<int, vector<int>> pq;
    int n, cmd;
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(cmd);
    }
    return 0;
}