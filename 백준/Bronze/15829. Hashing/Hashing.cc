#include <iostream>
#include <string>
#include <cmath>
#define M 1234567891
#define LL long long 
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l;
    LL ans=0;
    string str;
    cin >> l >> str;
    for (int i = 0; i < l; i++) {
        ans += (str[i]-96) * pow(31,i);
        ans% M;
    }
    cout << ans;
    return 0;
}