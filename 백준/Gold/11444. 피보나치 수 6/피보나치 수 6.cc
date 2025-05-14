#include <iostream>
#include <array>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll unsigned long long
#define MOD 1000000007
using namespace std;
using Matrix = array<array<ll, 2>, 2>;
const Matrix M = { {{1,1},{1,0}} };
Matrix mul(const Matrix& A, const Matrix& B) {
    return {{
        {{
            (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD,
            (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD
        }},
        {{
            (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD,
            (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD
        }}
    }};
}
Matrix pow(ll n) {
    if (n == 0) return M;
    if (n == 1) return M;
    if (n % 2) return mul(pow(n - 1), M);
    else {
        Matrix half = pow(n / 2);
        return mul(half, half);
    }
}
int main() {
    IOS;
    ll n;
    cin >> n;
    Matrix R = pow(n - 1);
    cout << R[0][0];
    return 0;
}

