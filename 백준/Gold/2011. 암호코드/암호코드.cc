#include <iostream>
#include <vector>
#include <string>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define MOD 1000000
using namespace std;

ll dp[5001] = { 0 };
int main() {
    IOS;
    dp[0] = 1;
    string str;
    cin >> str;
    if (str[0] == '0') {
        cout << 0;
        return 0;
    }
    vector<int> v(1,0);
    for (auto it : str) {
        int num = it - '0';
        v.push_back(num);
    }
    for (int i = 1; i < v.size();i++) {
        if(i-1 <= 0){
            dp[i] = dp[i - 1];
        }
        else if (v[i] == 0) {
            if (v[i - 1] == 1 || v[i - 1] == 2) {
                dp[i] = dp[i - 2];
            }
            else {
                cout << 0;
                return 0;
            }
        }
        else if (v[i-1]*10 + v[i] <= 26 && v[i-1]!=0) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        } else {
            dp[i] = dp[i - 1];
        }

    }
    cout << dp[v.size() - 1];
    return 0;
}