#include <iostream>
#include <vector>
#include <queue>
#define INF 400000
#define pii pair<int, int>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int V, E, K;
    cin >> V >> E >> K;

    vector<int> dist(V + 1, INF); // K에서 각 노드까지의 거리
    vector<vector<pii>> wv(V + 1); // 인접 리스트 (노드, 가중치)
    priority_queue<pii, vector<pii>, greater<pii>> pq; // (비용, 노드)

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        wv[u].push_back({ v, w });
    }

    dist[K] = 0;
    pq.push({ 0, K });

    while (!pq.empty()) {
        int cost = pq.top().first, node = pq.top().second;
        pq.pop();

        if (cost > dist[node]) continue; // 기존 거리보다 크면 무시

        for (auto& it : wv[node]) {
            int nextNode = it.first, weight = it.second;

            if (dist[nextNode] > dist[node] + weight) {
                dist[nextNode] = dist[node] + weight;
                pq.push({ dist[nextNode], nextNode });
            }
        }
    }

    // 결과 출력 (도달할 수 없는 경우 -1 출력)
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}
