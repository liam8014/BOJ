#include <iostream>
using namespace std;
const long long mod = 1000000007;
bool check(long long num) { return (num % 3 == 0); }
// 거듭제곱 함수
long long power(long long x, long long y) {
    long long res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
// 팩토리얼 함수
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact = (fact * i) % mod;
    }
    return fact;
}
// 중복순열 계산 함수
long long permutation(int a, int b) {
    long long fact_a_b = factorial(a + b);
    long long fact_a = factorial(a);
    long long fact_b = factorial(b);
    return (fact_a_b * power((fact_a * fact_b) % mod, mod - 2)) % mod;
}
int main() {
	int N, sum=0;
    bool isFound = false;
	cin >> N;
    for (int i = 0;i<N; i+= isFound?3:1) {
        if (check((N - i - 1) + 5 * (i + 1))) {
            sum =(sum +  permutation(N -i-1, i)) % mod;
            isFound = true;
        }  
        
    }
    cout << sum;
	return 0;
}