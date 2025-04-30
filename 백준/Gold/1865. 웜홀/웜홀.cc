#include <iostream>
#include <vector>
#include <algorithm>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 10000000
using namespace std;

int N, M, W, S, E, T;

int main() {
    SWS;
    int TC; cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        // 간선 목록을 따로 저장
        vector<tuple<int,int,int>> edges;
        // 인접 행렬은 그대로 유지해도 좋지만, relax 시에는 edges를 사용
        vector<vector<int>> dist(N+1, vector<int>(N+1, INF));
        for (int i = 1; i <= N; i++) dist[i][i] = 0;
        
        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            edges.emplace_back(S, E, T);
            edges.emplace_back(E, S, T);
        }
        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            edges.emplace_back(S, E, -T);
        }
        
        // 시작 정점을 1부터 N까지 각각 검사
        bool hasNegCycle = false;
        for (int start = 1; start <= N; start++) {
            // dist[start][*] 초기화
            for (int i = 1; i <= N; i++) dist[start][i] = INF;
            dist[start][start] = 0;
            
            // V-1번 반복
            for (int iter = 1; iter <= N-1; iter++) {
                bool updated = false;
                for (auto &e : edges) {
                    int u, v, w;
                    tie(u, v, w) = e;
                    if (dist[start][u] + w < dist[start][v]) {
                        dist[start][v] = dist[start][u] + w;
                        updated = true;
                    }
                }
                if (!updated) break;  // 더 이상 갱신 없으면 조기 종료
            }
            
            // 음수 사이클 검사
            for (auto &e : edges) {
                int u, v, w;
                tie(u, v, w) = e;
                if (dist[start][u] + w < dist[start][v]) {
                    hasNegCycle = true;
                    break;
                }
            }
            if (hasNegCycle) break;
        }
        
        cout << (hasNegCycle ? "YES\n" : "NO\n");
    }
    return 0;
}
