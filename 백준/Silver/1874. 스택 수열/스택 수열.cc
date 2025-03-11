#include <iostream>
#include <vector>
#include <stack>
#define SYNCSTDIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main(void) {
    SYNCSTDIO;
    stack<int> s;
    int n, cur=1,idx = 0; //cur : 다음 stack에 들어갈 수, idx : 현재 수열의 인덱스
    cin >> n;
    vector<int> v(n+1); 
    vector<char> ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (idx<n) {
        if (!s.empty()) {
            int top = s.top();
            if (top == v[idx]) {
                ans.push_back('-');
                s.pop();
                idx++;
            } else if (cur <= v[idx]) {
                ans.push_back('+');
                s.push(cur);
                cur++;
            } else {
                cout << "NO";
                idx = -1;
                break;
            }
        }
        else {
            ans.push_back('+');
            s.push(cur++);
        }
    }
    if(idx!=-1)
        for (auto it : ans) cout << it << '\n';
    return 0;
}