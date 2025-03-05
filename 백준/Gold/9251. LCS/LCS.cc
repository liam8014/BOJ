#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str1, str2;
    cin >> str1 >> str2;
    int l1 = str1.length() + 1, l2 = str2.length() + 1;
    vector<vector<int>> dp(l2, vector<int>(l1));
    for (int i = 1; i < l2; i++) {
        for (int j = 1; j < l1; j++) {
            dp[i][j] =
                (str1[j - 1] == str2[i - 1]) ?
                    dp[i - 1][j - 1] + 1 :
                    max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    cout << dp[l2-1][l1-1];
    return 0;
}

