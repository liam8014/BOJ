#include <iostream>
#include <string>
#include <stack>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
bool isAlpha(char c) { return(c >= 'A' && c <= 'Z'); }
int getRank(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        default : 
            return -1;
    }
}
int main() {
    SWS;
    string str;
    stack <char> stk;
    cin >> str;
    for (auto it : str) {
        if (isAlpha(it)) cout << it;
        else {
            switch (it)
            {
            case '*':
            case '/':
            case '+':
            case '-':
                while(1){
                    if (stk.empty() || getRank(it) > getRank(stk.top())) {
                        stk.push(it);
                        break;
                    }
                    else {
                        cout << stk.top();
                        stk.pop();
                    }
                }
                break;
            case '(':
                stk.push(it);
                break;
            case ')':
                while(1)
                {
                    if (stk.top() == '(') {
                        stk.pop();
                        break;
                    }
                    cout << stk.top();
                    stk.pop();
                }
                break;
            default:
                break;
            }
        }
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}