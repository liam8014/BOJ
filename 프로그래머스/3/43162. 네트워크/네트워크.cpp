#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

int solution(int n, vector<vector<int>> com) {
    int answer = 0;
    vector<bool> vst(n,false);
    for(int i =0;i<n;i++){
        if(vst[i]) continue;
        queue<int> q;
        vst[i] = true;
        q.push(i);
        while(!q.empty()){
            int frt = q.front();
            q.pop();
            for(int i = 0;i<n;i++){
                if(vst[i] || !com[frt][i]) continue;
                vst[i] = true;
                q.push(i);
            }
        }
        cout << endl;
        answer++;
    }
    return answer;
}