#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

bool canPlace(int n, int maxCus, int d) {
    for (int sy = 0; sy < n; ++sy) {
        vector<pair<int, int>> placed;
        placed.push_back({0, sy});

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j <= sy) continue;
                
                bool possible = true;
                for (auto& p : placed) {
                    int dist = abs(p.first - i) + abs(p.second - j);
                    if (dist < d) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    placed.push_back({i, j});
                    if (placed.size() == maxCus) return true;
                }
            }
        }
    }
    return false; 
}

int solution(int n, int m, vector<vector<int>> tt) {
    if (m == 0) return 0;

    int maxCus = 0;
    sort(tt.begin(), tt.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto& t : tt) {
        while (!pq.empty() && pq.top() < t[0]) {
            pq.pop();
        }
        pq.push(t[1]);
        maxCus = max(maxCus, (int)pq.size());
    }

    if (maxCus <= 1) return 0;

    int max_dist = 2 * (n - 1);
    for (int d = max_dist; d >= 1; --d) {
        if (canPlace(n, maxCus, d)) {
            return d;
        }
    }

    return 0;
}