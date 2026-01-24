#include <iostream>
#include <vector>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    int N, P, move = 0;
    cin >> N >> P;
    priority_queue<int> pq[6];
    while (N--) {
        int l, p;
        cin >> l >> p;
        l--;
        while (!pq[l].empty() && pq[l].top() > p) {
            move++;
            pq[l].pop();
        }
        if (pq[l].empty() || pq[l].top() != p) {
            move++;
            pq[l].push(p);
        }
    }
    cout << move;
    return 0;
}