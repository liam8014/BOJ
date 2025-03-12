#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector <int> v(N);
    map<int, int> m;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >>num;
        v[i] = num;
        m[num]++;
        sum += num;
    }
    vector<pair<int, int>> vp(m.begin(), m.end());
    sort(vp.begin(), vp.end(), [](pair<int, int> p1, pair<int, int>p2) {
        return(p1.second != p2.second ? p1.second > p2.second: p1.first < p2.first);
        });
    sort(v.begin(), v.end());
    
    cout << (int)round((double)sum / N) << '\n';
    cout << v[N/2] << '\n';

    if ((vp.size() == 1) || (vp[0].second != vp[1].second)) cout << vp[0].first << '\n';
    else cout << vp[1].first <<'\n';
    cout << (v.back() - v.front()) << '\n';

    return 0;
}