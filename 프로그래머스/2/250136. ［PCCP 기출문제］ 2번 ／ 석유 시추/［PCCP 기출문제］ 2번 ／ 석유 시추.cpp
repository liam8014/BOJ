/*

시작점과 끝점으로 연결하고, 정렬해서 탐색
새 석유 덩어리의 시작점이 이전 가장 빠른 종료점보다 작다면, out


*/
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
using PII = pair<int,int>;
struct nd{
  int start,end,amount; 
  bool operator<(nd n1) const{
      return n1.end < end;
  }
};

PII dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};
int solution(vector<vector<int>> land) {
    int answer = 0,curOil = 0, n = land.size(), m = land[0].size();
    priority_queue<PII,vector<PII>, greater<PII>> pq; //first : 종료점, second : 석유의 양
    for(int j = 0;j < m;j++) {
        for(int i = 0; i < n;i++){
            if(!land[i][j]) continue;
            queue<PII> q;
            int end = 0, sum = 0;
            q.push({i,j});
            land[i][j] = 0;
            while(!q.empty()){
                int r = q.front().first, c = q.front().second;
                end = max(end, c);
                sum++;
                q.pop();
                for(auto d : dir){
                    int nr = r + d.first, nc = c + d.second;
                    if(nr < 0 || nc < 0 || nr >=n || nc >= m) continue;
                    if(!land[nr][nc]) continue;
                    land[nr][nc] = 0;
                    q.push({nr,nc});
                }
            }
            while(!pq.empty() && pq.top().first < j){
                curOil -= pq.top().second;
                pq.pop();
            }
            curOil += sum;
            pq.push({end,sum});
            answer = max(answer,curOil);
        }
    }

    return answer;
}