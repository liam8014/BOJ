#include <string>
#include <vector>
#include <queue>

#define pii pair<int,int>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> v(n+1);
    vector<bool> vst(n+1, false);
    for(const auto& e : edge){
        v[e[0]].push_back(e[1]);
        v[e[1]].push_back(e[0]);
    }
    queue<pii> q;
    q.push({1,0});
    int maxDepth = 0;
    vst[1] = true;
    while(!q.empty()){
        int num = q.front().first, depth = q.front().second;

        q.pop();
        for(const auto& it : v[num]) {
            if( vst[it] )
                continue;
            vst[it] = true; 
            if(maxDepth < depth + 1){ // 더 긴 간선 등장
                maxDepth = depth + 1;
                answer = 1;
            }
            else if(maxDepth == depth+1){ 
                answer++;
            }
            q.push({it,depth+1});
        }
    }
    return answer;
}