#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#define INF 500001
/*
    플로이드-워셜? -> 시간 초과
    BFS하면서 업데이트?
    인접 행렬과 2차원 방문 비용 배열을 따로 운용
    한번 지나간다고 전부 업데이트 되진 않음
    시작-끝 경로만 업데이트 됨
    
*/
using namespace std;
struct nd{
    int pos, cost;
};
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int dst) {
    vector<int> answer;
    vector<vector<int>> a(n+1); //연결된 위치
    vector<int> dist(n+1, INF);
    for (auto r : roads){
        a[r[0]].push_back(r[1]);
        a[r[1]].push_back(r[0]);
    }
    vector<bool> vst(n+1, false);

    queue<nd> q;
    q.push({dst,0});
    vst[dst] = true;
    while(!q.empty()){
        int pos = q.front().pos, cost = q.front().cost;
        dist[pos] = min(dist[pos],cost);
        q.pop();
        for(auto it : a[pos]){
            if(vst[it]) continue;
            vst[it] = true;
            q.push({it,cost+1});
        }
    }

    for(auto s : sources){
        if(dist[s] == INF) dist[s] = -1;
        answer.push_back(dist[s]);
    }
    return answer;
}