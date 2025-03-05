#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define INF 100000000
int N, M;
using namespace std;
vector<vector<pii>> v;
int dijk(int startNode, int endNode) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector <int> costVector(N + 1, INF);
    costVector[startNode] = 0;
    pq.push({ 0,startNode});
    while (!pq.empty()) {
        int curCost = pq.top().first, curNode = pq.top().second;
        pq.pop();

        if (curCost > costVector[curNode]) continue;
        for (int i = 0; i < v[curNode].size(); i++) {

            int nextCost = curCost + v[curNode][i].first;
            int nextNode = v[curNode][i].second;
            if (nextCost < costVector[nextNode]) {
                costVector[nextNode] = nextCost;
                pq.push({nextCost,nextNode});
            }
        }
    }
    return costVector[endNode];

}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int startNode, endNode;
    cin >> N >> M;
    v.resize(N+1);
    for (int i = 0; i < M; i++) {
        int dptNode, arvNode, cost;
        cin >> dptNode >> arvNode >> cost;
        v[dptNode].push_back({ cost,arvNode });
    }
    cin >> startNode >> endNode;
    cout << dijk(startNode, endNode);
    return 0;
}