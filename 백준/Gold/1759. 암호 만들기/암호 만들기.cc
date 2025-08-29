#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int L, C;
vector<char> v,buff;
bool vst[28] = { false };
int countV() {
    int num = 0;
    if (vst['a' - 'a'])num++;
    if (vst['e' - 'a'])num++;
    if (vst['i' - 'a'])num++;
    if (vst['o' - 'a'])num++;
    if (vst['u' - 'a'])num++;
    return num;
}
void func(int idx) {
    buff.push_back(v[idx]);

    vst[v[idx]-'a'] = true;
    if (buff.size() == L) {
        if(countV() >= 1 && L - countV() >= 2 )
        {
            for (auto it : buff) {
                cout << it;
            }
            cout << '\n';
        }
    }
    else {
        for (int i = idx; i < C; i++) {
            if(!vst[v[i]-'a']) func(i);
        }
    }
    vst[v[idx] - 'a'] = false;
    buff.pop_back();
}
int main() {
    IOS;
    cin >> L >> C;
    
    for(int i=0;i<C;i++) {
        char input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < C; i++) {
        func(i);
    }
    return 0;
}