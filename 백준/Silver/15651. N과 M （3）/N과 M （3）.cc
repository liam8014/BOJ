#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N, M;
vector<int> v;
void bt(int num){
    v.push_back(num);
    if (v.size() == M) {
        for (auto it : v) cout << it << ' ';
        cout << '\n';
    }
    else {
        for (int i = 1; i <= N; i++)
            bt(i);
    }
    v.pop_back();
}
int main() {
    IOS;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        bt(i);
    return 0;
}