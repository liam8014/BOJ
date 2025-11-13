#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
using namespace std;
int main() {
    IOS;
    int N;
    cin >> N;
    vector<ll> v(N);
    vector<int> prev(N, -1) ; //길이 별 이전 인덱스
    vector<int> min_idx(N + 1, -1); //길이 별 최소 값의 인덱스
    for (int i = 0; i < N; i++) {cin >> v[i];}
    int L = 0;
    for (int i = 0; i < N; i++) {
        int lo = 1, hi = L, pos = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (v[min_idx[mid]] < v[i]) { // mid의 길이를 이루는 부분수열 마지막 원소의 최솟값이 현재 탐색중인 값보다 크다면? -> 길이를 늘림 -> 더 긴 길이에서도 확장할 수 있는지 확인
                pos = mid;
                lo = mid + 1;
            }
            else { // 작거나 같다면? -> 길이를 줄임
                hi = mid - 1;
            }
        }

        int new_len = pos + 1; // 이 벡터의 확장으로 커진 부분 수열의 길이
        prev[i] = (new_len > 1) ? min_idx[pos] : -1; // 부분 수열의 첫 원소는 이전 인덱스를 저장하지 않음
        min_idx[new_len] = i; 
        if (new_len > L) L = new_len;
    }
    vector<int> lis(L);
    int cur = min_idx[L];
    for (int k = L - 1; k >= 0; k--) {
        lis[k] = v[cur];
        cur = prev[cur];
    }

    cout << lis.size() <<'\n';
    for (auto l : lis) {
        cout << l << ' ';
    }

    return 0;
}