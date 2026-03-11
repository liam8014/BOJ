#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define LL long long
#define PII pair<int,int>
using namespace std;
int N;
vector<int> v;
int main() {
    IOS;
    cin >> N;
    for(int i =0;i<N;i++){
        int num;
        cin >> num;
        auto pos = lower_bound(v.begin(), v.end(),num);
        if (pos == v.end()) {
            v.push_back(num);
        }
        else {
            *pos = num;
        }
    }
    cout << N - (int)v.size();
    return 0;
}