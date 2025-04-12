#include <iostream>
#include <string>
#include <set>

#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    SWS;
    int n, ans=0;
    set<string> vst;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "ENTER") {
            vst.clear();
        }
        else if(vst.find(str)==vst.end()){
            vst.insert(str);
            ans++;
        }
    }
    cout << ans;
    return 0;
}