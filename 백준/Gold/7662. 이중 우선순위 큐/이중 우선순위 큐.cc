#include <iostream>
#include <queue>
#include <unordered_map>

#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

int main() {
    SWS;
    int T; cin >> T;
    while (T--) {
        int k;
        cin >> k;
        priority_queue<int> maxq;  // 최대 힙
        priority_queue<int, vector<int>, greater<int>> minq;  // 최소 힙
        unordered_map<int, int> count;  // 각 숫자의 등장 횟수

        while (k--) {
            char cmd;
            int n;
            cin >> cmd >> n;
            if (cmd == 'I') {
                maxq.push(n);
                minq.push(n);
                count[n]++;
            } else if (cmd == 'D') {
                if (count.empty()) continue;  // 비어있으면 무시
                
                if (n == 1) {  // 최댓값 삭제
                    while (!maxq.empty() && count[maxq.top()] == 0)
                        maxq.pop();  // 유효하지 않은 값 제거
                    
                    if (!maxq.empty()) {
                        count[maxq.top()]--;
                        maxq.pop();
                    }
                } else if (n == -1) {  // 최솟값 삭제
                    while (!minq.empty() && count[minq.top()] == 0)
                        minq.pop();  // 유효하지 않은 값 제거
                    
                    if (!minq.empty()) {
                        count[minq.top()]--;
                        minq.pop();
                    }
                }
            }
        }

        while (!maxq.empty() && count[maxq.top()] == 0)
            maxq.pop();
        while (!minq.empty() && count[minq.top()] == 0)
            minq.pop();

        if (maxq.empty() || minq.empty()) 
            cout << "EMPTY\n";
        else 
            cout << maxq.top() << ' ' << minq.top() << '\n';
    }
    return 0;
}
