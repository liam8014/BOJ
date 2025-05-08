#include <iostream>
#include <vector>
#include <algorithm>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    SWS;
    int N;
    vector<int> v;
    cin >> N;
    for (;N>0;N/=10) v.push_back(N % 10);
    sort(v.begin(), v.end(),greater<int>());
    for (auto it : v) cout << it;
    return 0;
}