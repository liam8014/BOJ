#include <iostream>
#include <cmath>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    SWS;
    long long X,Y,Z,ans=0;
    cin >> X >> Y;
    Z = (long long)(trunc((double)Y++ * 100 / X++));
    if(Z<99) {
        while (1) {
            ans++;
            long long Z2 = (long long)(trunc((double)Y++ * 100 / X++));
            if (Z != Z2) break;
        }
        cout << ans;
    } else  cout << -1;
    return 0;
}