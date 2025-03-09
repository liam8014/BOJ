#include <iostream>
#include <vector>
#define SYNCSTDIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main(void) {
    SYNCSTDIO;
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    vector<int> rank(N, 0);
    for (int i = 0; i < N; i++) 
        cin >> v[i].first >> v[i].second;
    for (int i = 0; i < N; i++) {
        rank[i] = 1;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if ((v[i].first < v[j].first) && (v[i].second < v[j].second)) rank[i]++;
        }
    }
    for (auto it : rank) cout << it << ' ';
    return 0;
}