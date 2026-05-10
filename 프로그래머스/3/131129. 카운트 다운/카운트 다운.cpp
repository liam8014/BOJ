#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 100000
using namespace std;
vector<int> dp(INF+1, INF+1);
vector<int> BnS(INF+1, 0);
vector<int> solution(int t) {
    for(int i = 1; i<=20;i++){
        BnS[i] = 1;
        int arr[3] = {i, i*2, i*3};
            for(auto it : arr){
                if(it <= t){
                    dp[it] = 1;
                }
            }
    }
    if(t >= 50){
        BnS[50] = dp[50] = 1;
    }
    for(int i = 1; i<=t;i++){
        for(int j =1;j<=20;j++){
            int arr[3] = {i+j, i+j*2, i+j*3};
            for(auto it : arr){
                if(it <= t){
                    if(dp[it] > dp[i]+1){
                        dp[it] = dp[i]+1;
                    }
                    if(dp[it] == dp[i]+1 && it==i+j){
                        BnS[it] = max(BnS[it], BnS[i] + 1);
                    }
                }
            }
        }
        if(i+50 <= t){
            if(dp[i+50] > dp[i]+1){
                dp[i+50] = dp[i]+1;
            }
            if(dp[i+50] == dp[i]+1){
                BnS[i+50] = max(BnS[i+50], BnS[i] + 1);
            }
        }
    }
    vector<int> answer = {dp[t],BnS[t]};
    return answer;
}