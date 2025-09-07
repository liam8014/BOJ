#include <iostream>
#include <string>
#include <list>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    int M;
    string str;
    cin >> str >> M;
    list<char> L;
    for (auto it : str) {
        L.push_back(it);
    }
    list<char>::iterator csr = L.end();
    while (M--) {
        char cmd;
        
        cin >> cmd;
        switch (cmd)
        {
        case 'L':
            if (csr != L.begin())
                csr--;
            break;
        case 'D':
            if (csr !=L.end())
                csr++;
            break;
        case 'B':
            if (csr != L.begin()) {
                L.erase(prev(csr));
            }
            break;
        case 'P':
            char add;
            cin >> add;
            L.insert(csr,add);
            break;
        default:
            break;
        }

    }
    for (auto it : L) {
        cout << it;
    }
    return 0;
}