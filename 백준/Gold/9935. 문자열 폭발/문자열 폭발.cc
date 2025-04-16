#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

string input, bomb;
int index(char ch) { return (ch - '0'); }
void ps(stack<int> s) {
    string str;
    while (!s.empty()) {
        if (s.top() < '0') {
            string sstr = bomb.substr(0, s.top());
            reverse(sstr.begin(), sstr.end());
            str += sstr;
        }
        else { str += s.top();}
        s.pop();
    }
    reverse(str.begin(), str.end());
    cout << (str.empty() ? "FRULA" : str);
}
int main() {
    SWS;
    cin >> input >> bomb;
    stack<int> stk;
    int list[75] = { 0 }, idx = 1, depth = 1, length = bomb.length(); //depth : 다음 들어와야할 순서
    for (auto it : bomb) list[index(it)] = idx++;
    for (auto it : input) {   
        if (list[index(it)] == 1) { //새 line 시작
            depth = 1;
            stk.push(depth++);
        } else if (list[index(it)] == depth) { //기존 line 증가
            stk.pop();
            stk.push(depth++);
        }
        else { //line 초기화
            depth = 1;
            stk.push(it);
        }
        if (depth-1 == length) { //폭탄 line 완성
            stk.pop();
            if (stk.empty() || stk.top() >= '0')  depth = 1;
            else depth = stk.top()+1;
        }
    }
    ps(stk);
    return 0;
}