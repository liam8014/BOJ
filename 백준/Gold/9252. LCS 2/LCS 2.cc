#include <iostream>
#include <string>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dp[1001][1001] = { 0 };
int main() {
    IOS;
    string str1, str2, ansS;
    cin >> str1 >> str2;
    int l1 = str1.length() + 1, l2 = str2.length() + 1, ans;
    for (int i = 1; i < l2; i++) {
        for (int j = 1; j < l1; j++) {
            dp[i][j] =
                (str1[j - 1] == str2[i - 1]) ?
                dp[i - 1][j - 1] + 1 :
                max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    ans = dp[l2 - 1][l1 - 1];
    int i = l2 - 1, j = l1 - 1;
    while (ansS.length() < ans) {
        if (str1[j - 1] == str2[i - 1]) {
            ansS = str1[j - 1] + ansS;
            i--; j--;
        }
        else {
            if(dp[i][j] == dp[i][j-1]){
                j--;
            }
            else {
                i--;
            }

        }
    }
    cout << ans;
    if (ans) {
        cout << '\n' << ansS;
    }
    return 0;
}