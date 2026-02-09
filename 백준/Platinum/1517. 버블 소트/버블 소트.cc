#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N;
vector<ll> v;
vector<vector<ll>> tree;
ll ans = 0;

void build(int node, int start, int end) {
    if (start == end) {
        tree[node].push_back(v[start]);
        return;
    }

    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);

    tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
    merge(tree[node * 2].begin(), tree[node * 2].end(),
        tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
        tree[node].begin());
}

ll calcSwap(int node, int start, int end, int left, int right, ll val) {
    if (start > right || end < left)
        return 0;

    if (left <= start && end <= right) {
        return lower_bound(tree[node].begin(), tree[node].end(), val)
            - tree[node].begin();
    }

    int mid = (start + end) / 2;
    return calcSwap(node * 2, start, mid, left, right, val)
        + calcSwap(node * 2 + 1, mid + 1, end, left, right, val);
}

int main() {
    IOS;

    cin >> N;
    v.resize(N + 1);
    tree.resize(4 * N + 1);

    for (int i = 1; i <= N; i++)
        cin >> v[i];

    build(1, 1, N);

    for (int i = 1; i <= N; i++) {
        ans += calcSwap(1, 1, N, i + 1, N, v[i]);
    }

    cout << ans;
    return 0;
}