#include <iostream>
#include <string>
#include <cmath>
#define M 1234567891LL
#define ULL unsigned long long 
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l;
    ULL ans=0, p=1;
    string str;
    cin >> l >> str;
    for (int i = 0; i < l; i++) {
        ans += ((str[i] - 'a' + 1) * p) % M;
        p = (p * 31) % M;
    }
    cout << ans % M;
    return 0;
}