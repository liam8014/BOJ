#include <iostream>
#include <vector>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
struct cand {
    int rec, num, time;
};
struct cmp {
    bool operator() (const cand& c1, const cand& c2) {
        return(c1.rec == c2.rec ? c1.time > c2.time : c1.rec > c2.rec);
    }
};
int main() {
    IOS;
    int  N, R;
    cin >> N >> R;
    vector<int> v(101, 0);// 추천 수를 저장해놓다가 삭제 위기에 놓이면 비교
    priority_queue < cand, vector<cand>, cmp> pq;
    int time = 1;
    for (int i = 0; i < R; i++) {
        int num;
        cin >> num;
        if (v[num] == 0) { // 첫 추천
            if (pq.size() == N) {  //더 이상 추천 불가
                while (pq.top().rec != v[pq.top().num]) {
                    pq.push({ v[pq.top().num], pq.top().num, pq.top().time });
                    pq.pop();
                }
                v[pq.top().num] = 0;
                pq.pop();
            }
            pq.push({ 1,num,time++ });
        }
        v[num]++;
    }
    for (int i = 1; i <= 100; i++) {
        if (v[i] > 0) cout << i << ' ';
    }
    return 0;
}