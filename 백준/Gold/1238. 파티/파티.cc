#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 9000000
#define ii pair<int, int>
using namespace std;
vector<pair<int, int>> v[1000];
vector<int> ans;

int n, m, x; // n : 학생 수, m : 도로의 수, x: 모이는 마을

void dijk(int start) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({ 0, start });
    vector<int> d(n,INF); // 최소 시간

    d[start] = 0;

    while (!pq.empty()) {
        int cur_time = pq.top().first; // 그룹->현재 노드의 시간
        int cur = pq.top().second; //현재 노드
        pq.pop();
        
        if (d[cur] < cur_time) continue; // 그룹->현재 노드의 시간이 이미 최소 시간보다 크면 패스
        
        for (int i = 0; i < v[cur].size(); i++) {
            int next_time = cur_time + v[cur][i].first;
            int next_idx = v[cur][i].second;
            if (next_time < d[next_idx]) {
                d[next_idx] = next_time;
                pq.push({ next_time,next_idx });
            }

        }
    }
    if(start == x) {//도착점 -> 출발점
        for (int i = 0; i < n; i++) {
            if(i!=x) ans[i]+=d[i];
        }
    }
    else { ans[start] += d[x]; }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> x;
    x--;
    ans.resize(n,0);
    for (int i = 0; i < m; i++) {
        int start, end, time;
        cin >> start >> end >> time;
        start--; end--;
        v[start].push_back({ time, end });
    }
    for (int i = 0; i < n; i++) { dijk(i); }
    cout << *max_element(ans.begin(), ans.end());
    return 0;
}