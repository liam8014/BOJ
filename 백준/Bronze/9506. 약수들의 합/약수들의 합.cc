#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    IOS;
    while(1){
        int num = 0, sum = 0;
        cin >> num;
        if (num == -1) break;
        vector<int> v;
        for (int i = 1; i < num; i++) {
            if (num % i==0) {
                sum += i;
                v.push_back(i);
            }
        }
        if (sum==num) {
            cout << num << " = 1";
            for (int i = 1; i < v.size(); i++) {
                cout << " + " << v[i];
            }
        }
        else {
            cout << num << " is NOT perfect.";
        }
        cout << '\n';
    }

    return 0;
}