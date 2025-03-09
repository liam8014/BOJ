#include <iostream>
#include <vector>
#include <algorithm>
#define SYNCSTDIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main(void) {
    SYNCSTDIO;
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) 
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(),
        [](pair<int,int> p1, pair<int, int> p2){
            return (p1.second != p2.second ? p1.second < p2.second : p1.first < p2.first);
        }
    );
    for (auto it : v) {
        cout << it.first << ' ' << it.second << '\n';
    }
    return 0;
}