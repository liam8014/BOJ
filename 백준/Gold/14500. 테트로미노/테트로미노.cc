#include <iostream>
#include <vector>
#include <algorithm>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int N, M, ans = 0;
vector<vector<int>> v;
vector< vector<pair<int, int>> > forms = {
	// O
	{ {0,0},{0,1},{1,0},{1,1} },

	//I
	{ {0,0},{0,1},{0,2},{0,3} },
	{ {0,0},{1,0},{2,0},{3,0} },

	//T
	{ {0,0},{0,1},{0,2},{-1,1} },
	{ {0,0},{1,0},{2,0},{1,1} },
	{ {0,0},{0,1},{0,2},{1,1} },
	{ {0,0},{1,0},{2,0},{1,-1} },

	//J
	{ {0,0},{1,0},{2,0},{2,1} },
	{ {0,0},{0,1},{0,2},{-1,2} },
	{ {0,0},{0,1},{1,1},{2,1} },
	{ {0,0},{1,0},{0,-1},{0,-2} },

	// L
	{ {0,0},{1,0},{2,0},{0,1} },
	{ {0,0},{0,1},{0,2},{1,0} },
	{ {0,0},{1,0},{2,0},{2,-1} },
	{ {0,0},{1,0},{1,1},{1,2} },

	// S
	{ {0,0},{1,0},{1,1},{2,1} },
	{ {0,0},{0,1},{-1,1},{-1,2} },
	{ {0,0},{1,0},{1,-1},{2,-1} },
	{ {0,0},{0,1},{1,1},{1,2} },

	//Z
	{ {0,0},{1,0},{0,1},{-1,1} },
	{ {0,0},{0,1},{1,1},{1,2} },
	{ {0,0},{1,0},{0,-1},{-1,-1} },
	{ {0,0},{0,1},{-1,1},{-1,2} },
};
int mino(int row, int col, vector<pair<int, int>> form) {
	int sum=0;
	for (auto it : form) {
		int nrow = row + it.first, ncol = col + it.second;
		if ((nrow < 0 || nrow >= N) || (ncol < 0 || ncol >= M)) return -1;
		sum += v[nrow][ncol];
	}
	return sum;
}

int main() {
	SWS;
	cin >> N >> M;
	v.resize(N,vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (auto it : forms)
			ans = max(mino(i, j, it), ans);
		}
	}
	cout << ans;
	return 0;
}