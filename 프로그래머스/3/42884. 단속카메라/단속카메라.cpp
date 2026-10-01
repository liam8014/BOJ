#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(const auto& r : routes){
        pq.push({r[0],r[1]});
    }
    if(!pq.empty()) {        
        int cam = pq.top().second;
        pq.pop();   
        answer++;
        while(!pq.empty()){
            if( cam > pq.top().second ){
                cam = pq.top().second;
            }
            else if( cam < pq.top().first ){
                cam = pq.top().second;
                answer++;
            }
            pq.pop();
        }
    }
    return answer;
}