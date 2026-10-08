#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> a) {
    int n = a.size();
    int answer = 0;
    vector<int> min1(n,0),min2(n,0);
    min1[0] = a[0];
    min2[n-1] = a[n-1];
    for(int i = 1;i<n;i++){
        min1[i] = min( min1[i-1], a[i] );
        min2[n-i-1] = min( min2[n-i], a[n-i-1] );
    }

    for(int i = 0;i<n;i++){
        if(a[i] <= min1[i] || a[i] <= min2[i]){
            answer++;
        }
    }

    return answer;
}