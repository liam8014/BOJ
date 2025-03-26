#include <iostream>
#include <algorithm>
#include <vector>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
struct camera {
	int r;
	int c;
	int num; //몇 번 카메라인지
	int type; //카메라의 회전 유형
};


vector<vector<int>> v, v_init;
vector<pair<int, int>> cam;
int N, M;
int showCamera(int r, int c, int dir) {
	pair <int, int> pos;
	int res = 0;
	switch (dir) {
	case 1:
		pos = { 1,0 };
		break;
	case 2:
		pos = { -1,0 };
		break;
	case 3:
		pos = { 0,-1 };
		break;
	case 4:
		pos = { 0,1 };
		break;
	};
	while (
		r + pos.first >= 0
		&& c + pos.second >= 0
		&& r + pos.first < N
		&& c + pos.second < M
		&& v[r + pos.first][c + pos.second] != 6
		) {
		r += pos.first;
		c += pos.second;
		if (v[r][c] == 0) {
			res++;
			v[r][c] = 7;
		}
	}
	return res;
}
int checkCase(vector<camera> cams) {
	v = v_init; //사각지대 파악을 위한 2차원 배열
	int res = 0;
	for (auto i : cams) {
        switch (i.num) {
        case 1:
            res += showCamera(i.r, i.c, i.type);
            break;
        case 2:
            switch (i.type) {
            case 1:
                res += showCamera(i.r, i.c, 1);
                res += showCamera(i.r, i.c, 2);
                break;
            case 2:
                res += showCamera(i.r, i.c, 3);
                res += showCamera(i.r, i.c, 4);
                break;
            };
            break;
        case 3:
            switch (i.type) {
            case 1:
                res += showCamera(i.r, i.c, 1);
                res += showCamera(i.r, i.c, 3);
                break;
            case 2:
                res += showCamera(i.r, i.c, 1);
                res += showCamera(i.r, i.c, 4);
                break;
            case 3:
                res += showCamera(i.r, i.c, 2);
                res += showCamera(i.r, i.c, 3);
                break;
            case 4:
                res += showCamera(i.r, i.c, 2);
                res += showCamera(i.r, i.c, 4);
                break;
            };
            break;
        case 4:
            switch (i.type) {
            case 1:
                res += showCamera(i.r, i.c, 1);
                res += showCamera(i.r, i.c, 2);
                res += showCamera(i.r, i.c, 3);
                break;
            case 2:
                res += showCamera(i.r, i.c, 1);
                res += showCamera(i.r, i.c, 2);
                res += showCamera(i.r, i.c, 4);
                break;
            case 3:
                res += showCamera(i.r, i.c, 1);
                res += showCamera(i.r, i.c, 3);
                res += showCamera(i.r, i.c, 4);
                break;
            case 4:
                res += showCamera(i.r, i.c, 2);
                res += showCamera(i.r, i.c, 3);
                res += showCamera(i.r, i.c, 4);
                break;
            };
            break;
        case 5:
            res += showCamera(i.r, i.c, 1);
            res += showCamera(i.r, i.c, 2);
            res += showCamera(i.r, i.c, 3);
            res += showCamera(i.r, i.c, 4);
            break;
        };
	}

	return res;
}
vector<int> rotateType = { 0, 4, 2, 4, 4, 1 }; // 각 CCTV 유형별 회전 경우의 수
int ans = 0;

void dfs(int depth, vector<camera>& cams) {
    if (depth == cams.size()) {
        ans = max(ans, checkCase(cams)); // 사각지대 최소화
        return;
    }

    int maxType = rotateType[cams[depth].num]; // 현재 CCTV의 회전 가능 개수
    for (int t = 1; t <= maxType; t++) {
        cams[depth].type = t;  // CCTV의 감시 방향 변경
        dfs(depth + 1, cams);   // 다음 CCTV 탐색
    }
}

int main() {
	SWS;
	vector<camera> cams;
	cin >> N >> M;
    int ans_max = 0;
	v.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] >= 1 && v[i][j] <= 5) cams.push_back({ i,j,v[i][j],2 });
            if (v[i][j] == 0) ans_max++;
		}
	}
	v_init = v;

    dfs(0, cams); // 모든 CCTV의 방향을 탐색하는 DFS 실행
    ans = ans_max - ans;
    cout << ans; // 최소 사각지대 출력
	return 0;
}