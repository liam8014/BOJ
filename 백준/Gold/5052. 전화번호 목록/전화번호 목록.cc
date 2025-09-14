#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int T;
int main() {
    IOS;
    cin >> T;
    
    while (T--) {
        unordered_map<string, bool> vst;
        int N;
        bool ans = true;
        vector<string> vs;
        cin >> N;
        while (N--) {
            string str;
            cin >> str;
            vs.push_back(str);
            vst[str] = true;
        }
        for (auto s : vs) {
            if (!ans) break;
            string cutS;
            for (int i = 0; i < s.size()-1; i++) {
                cutS += s[i];
                if (vst[cutS]) {
                    ans = false;
                    break;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}