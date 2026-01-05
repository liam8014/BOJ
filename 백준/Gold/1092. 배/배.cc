#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    int N, M, ans = 0;
    cin >> N;
    vector<int> crain(N);
    for (int i = 0; i < N; i++) { cin >> crain[i]; }
    sort(crain.begin(), crain.end(), greater<int>());
    cin >> M;
    list<int> freight;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        freight.push_back(num);
    }
    freight.sort();
    if (crain.front() < freight.back()) {
        cout << -1;
        return 0;
    }
    while (!freight.empty()) {
        ans++;
        for (const auto& c : crain) {
            auto lb = upper_bound(freight.begin(), freight.end(), c);
            if (lb == freight.begin()) { break; }
            freight.erase(--lb);
        }
    }
    cout << ans;
    return 0;
}