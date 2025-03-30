#include <iostream>
#include <vector>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
	SWS;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			cout << v[i][j] + num << ' ';
		}
		cout << '\n';
	}
	return 0;
}