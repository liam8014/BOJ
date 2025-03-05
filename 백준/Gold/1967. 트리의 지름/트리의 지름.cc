#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector<int>> child; //해당 노드의 자식 노드
vector <int> parent; //해당 노드의 부모 노드의 가중치
vector <pair <int, int>> LR; //해당 노드를 루트로 했을 때 각 자식 노드 합의 최댓값, 자식 노드의 최댓값
int n,ans=0;
void dfs(int nd) {//nd는 입력 node
    if (child[nd].size() != 0) {//leaf 노드가 아닐 때
        for (auto it : child[nd]) dfs(it);
        int firstLR = 0, secondLR = 0;
        for (auto it : child[nd])
        {
            if (firstLR < LR[it].second + parent[it]) {
                secondLR = firstLR;
                firstLR = LR[it].second + parent[it];
            }
            else if (secondLR < LR[it].second + parent[it]) {
                secondLR = LR[it].second + parent[it];
            }
        }
        LR[nd].first = firstLR + secondLR;
        LR[nd].second = firstLR;
        ans = max(ans, LR[nd].first);
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    child.resize(n + 1);
    parent.resize(n + 1);
    LR.resize(n + 1);
    for (int i = 0; i < n-1; i++) {
        int p, c, a;//부모, 자식, 가중치
        cin >> p >> c >> a;
        parent[c] = a; //c와 부모 사이 간선의 가중치
        child[p].push_back(c);
    }
    dfs(1);
    cout << ans;
    return 0;
}
