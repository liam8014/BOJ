#include <iostream>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, r, c, num;
    cin >> n >> r >> c;
    n = pow(2,n);
    num = r * n + c;
    int start = 0, end = n * n - 1;
    while (n>2) {
        int quat = 0;
        if (num / n >= n / 2) { quat += 2; }
        if (num % n >= n / 2) { quat += 1; }
        n /= 2;
        switch (quat) {
            case 0:
                end -= pow(n,2) * 3;
                break;
            case 1:
                start += pow(n, 2);
                end -= pow(n, 2) * 2;
                c -= n;
                break;
            case 2:
                start += pow(n, 2) * 2;
                end -= pow(n, 2);
                r -= n;
                break;
            case 3:
                start += pow(n, 2) * 3;
                r -= n;
                c -= n;
                break;
        }
        num = r * n + c;
    }
    cout << start + num;
    return 0;
}
