#include <iostream>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    int n, ans=0;
    cin >> n;
    int s = n / 5;
    if ((n - s * 5) % 2 == 1 && s >= 1) { s--; }
    n -= s * 5;
    ans += s;
    if (n % 2 == 1) { ans = -1; }
    else { ans += n / 2; }
    cout << ans;
    return 0;
}
