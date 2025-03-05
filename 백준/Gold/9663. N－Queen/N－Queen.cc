#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int N;
int countNQueens(int row, vector<int>& positions) {
    if (row == N) {
        return 1; // 모든 퀸을 성공적으로 배치한 경우
    }

    int count = 0;
    for (int col = 0; col < N; col++) {
        bool valid = true;

        // 현재 열과 대각선 체크
        for (int prevRow = 0; prevRow < row; prevRow++) {
            int prevCol = positions[prevRow];
            if (prevCol == col || abs(prevCol - col) == abs(prevRow - row)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            positions[row] = col; // 현재 행에 퀸 배치
            count += countNQueens(row + 1, positions); // 다음 행으로 재귀 호출
        }
    }
    return count;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;

    vector<int> positions(N); // 각 행에 퀸의 열 위치 저장
    int ans = countNQueens(0, positions); // 0행부터 시작
    cout << ans;

    return 0;
}
