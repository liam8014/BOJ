#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    int F, S, G, U, D,ans = 0;
    cin >> F >> S >> G >> U >> D;
    vector<bool> vst(F + 1, false);
    while (S!=G) {
        if (vst[S]) {
            ans = -1;
            break;
        }
        vst[S] = true;

        if (S > G && S - D > 0) {
            S -= D;
        }
        else if ( S + U <= F ) {
            S += U;
        }
        else if (S - D > 0) {
            S -= D;
        }
        ans++;
    }

    if (ans == -1) {
        cout << "use the stairs";
    }
    else {
        cout << ans;
    }
    return 0;
}