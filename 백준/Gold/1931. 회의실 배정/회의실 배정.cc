#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);
    }
    int n;
    cin >> n;
    vector <pair<int, int>>v(n), ans;
    for (int i = 0; i < v.size(); i++) {
        int a, b;
        cin >> a >> b;
        v[i] = { a,b };
    }
    sort(
        v.begin(), v.end(),
        [] (pair<int, int> p1, pair<int, int> p2) -> bool{
            bool res = true;
            if ((p1.second) != (p2.second)) {
                return (p1.second) < (p2.second);
            }
            else if (p1.first == p1.second) {
                return false;
            }
            else if (p2.first == p2.second) {
                return true;
            }
            else return (p1.second - p1.first) < (p2.second - p2.first);
        }
    );

    ans.push_back(v[0]);
    for (int i = 1; i < v.size();i++) {
        if(ans.back().second <= v[i].first) ans.push_back(v[i]);
    }

    cout << ans.size();
    return 0;
}
