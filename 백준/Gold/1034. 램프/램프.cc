#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
unordered_map<string, int> um;
int N, M,K, ans=0;
bool check(const string& str) {
    int cnt = 0;
    for (auto c: str)   if(c=='0') cnt++;
    return cnt <= K &&
        (K - cnt) % 2 == 0;
}
int main() {
    IOS;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        um[str]++;
    }
    cin >> K;
    for (const auto& s : um) {
        if (ans < s.second && check(s.first)) ans = s.second;
    }
    cout << ans;
    return 0;
}