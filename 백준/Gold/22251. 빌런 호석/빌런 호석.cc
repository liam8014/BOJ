#include <iostream>
#include <vector>
#include <cmath>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N, K, P, X;
int cost[10][10] = { 0 };
bool num[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};
void build() {
    for (int i = 0; i < 10; i++) {
        for (int j = i+1; j < 10; j++) {
            int cnt = 0;
            for (int k = 0; k < 7; k++) {
                if (num[i][k] != num[j][k])
                    cnt++;
            }
            cost[i][j] = cost[j][i] = cnt;
        }
    }
}
bool canChange(int T) {
    int S = X,sum=0;
    for (int i = K; i > 0; i--) {
        int digit = pow(10,i-1);
        sum += cost[S / digit][T / digit];
        S %= digit;
        T %= digit;
        if (sum > P) return false;
    }
    return true;
}
int main() {
    IOS;
    build();
    int ans = 0;
    cin >> N >> K >> P >> X;
    for (int i = 1; i <= N; i++) {
        if (i == X) continue;
        if (canChange(i))
            ans++;
    }
    cout << ans;
    return 0;
}