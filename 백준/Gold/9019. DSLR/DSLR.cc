#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
int D(int num) {
    return (num * 2) % 10000;
}
int S(int num) {
    return (num == 0 ? 9999 : num - 1);
}
int L(int num) {
    return ((num * 10) + (num / 1000)) % 10000;
}
int R(int num) {
    return ((num / 10) + (num % 10)*1000);
}
int main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int input, output;
        cin >> input >> output;
        vector<bool> vst(10000);
        queue<pair<int, string>> q;
        q.push({ input, "" });
        vst[input] = true;
        while (!q.empty()) {
            int num = q.front().first;
            string cmd = q.front().second;
            bool found = false;
            q.pop();
            vector<pair<int, char>> new_list = { {D(num),'D' }, {S(num),'S' }, {L(num),'L' }, {R(num),'R'} };

            for (auto it : new_list) {
                if (vst[it.first]) continue;
                if (it.first == output) {
                    cout << cmd + it.second << '\n';
                    found = true;
                    break;
                }
                q.push({ it.first, cmd + it.second });
                vst[it.first] = true;
            }
            if (found) break;
        }
    }
    return 0;
}