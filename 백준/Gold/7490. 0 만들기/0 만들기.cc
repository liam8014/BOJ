#include <iostream>
#include <vector>

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<char> ops;
int N;
void calc() {
    vector<int> nv;

    for (int i = 1; i <= N;i++) {
        int num = i;
        while (i-1<ops.size() && ops[i-1]==' ') {
            num = num * 10 + (++i);
        }
        nv.push_back(num);
    }

    int sum = nv[0];

    for (int i = 1, j = 0; i < nv.size(); i++,j++) {
        while (j < ops.size() && ops[j] == ' ') {
            j++;
        }
        if (ops[j] == '+') {
            sum += nv[i];
        }
        else {
            sum -= nv[i];
        }
    }

    if (sum == 0) {
        for (int i = 0; i < N; i++) {
            cout << i + 1;
            if (i < ops.size()) {
                cout << ops[i];
            }
        }
        cout << '\n';
    }
}
void solve(int depth) {
    if (depth == N - 1) {
        calc();
        return;
    }
    char candidates[3] = { ' ', '+', '-' };
    for (int i = 0; i < 3; i++) {
        ops.push_back(candidates[i]);
        solve(depth + 1);
        ops.pop_back();
    }
}

int main() {
    IOS;
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        solve(0);
        cout << '\n';
    }
    return 0;
}