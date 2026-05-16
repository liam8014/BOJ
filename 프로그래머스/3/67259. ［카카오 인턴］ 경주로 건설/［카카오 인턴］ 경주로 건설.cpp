#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include<algorithm>
#define PII pair<int,int>
#define INF 10000
using namespace std;
PII dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};

struct nod {
    int r,c,w,d; //d는 1이면 가로, 2면 세로
};
int solution(vector<vector<int>> v) {

    int answer = 0;
    int n = v.size(), m=v[0].size();
    vector<vector<vector<int>>> vst(n,vector<vector<int>>(m,vector<int>(2,INF)));
    stack<nod> stk;
    stk.push({0,0,0,0});
    vst[0][0][0] = 0;
    vst[0][0][1] = 0;
    while(!stk.empty()){
        int r = stk.top().r, c=stk.top().c, w = stk.top().w, d = stk.top().d;
        stk.pop();
        for(int i=0;i<4;i++){
            int nr = dir[i].first + r, nc = dir[i].second + c,
            nd = (i < 2 ? 1 : 2),
            nw = (d!=0 && nd != d) ?
                  w + 6 : 
                  w + 1;
            if(nr < 0 || nc < 0 || nr >= n || nc >= m || vst[nr][nc][nd-1] < nw || v[nr][nc]) continue;
            vst[nr][nc][nd-1] = nw;
            stk.push({nr,nc,nw,nd});
        }
    }

    return min(vst[n-1][m-1][0],vst[n-1][m-1][1])  * 100;
}