/*
소수인지 아닌지 나왔으면?
최대 약수는 가장 작은 약수로 나눈 수.!
*/
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#define MAX 10'000'000
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> v;
    v.resize(end - begin + 1, 0);
    for(int i = 1; i <= sqrt(end) && i <= MAX;i++){
        //cout << "i : " << i <<'\n';
        for(long long j = begin/i * i; j <= end;j+=i){
            if(j < begin || j < i*2) continue;
            //cout << "   j : " << j  <<'\n';
            v[j - begin] = max((int)v[j - begin], (int)(i==1 ? 1 :
                                    (j/i > MAX ? i : j/i) )) ;
        }
    }
    return v;
}