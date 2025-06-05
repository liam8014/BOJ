#include <iostream>
#include <vector>
#include <stack>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<vector<int>> v(9,vector<int>(9,0));
vector<pair<int, int>> blanks;
bool foundAns = false;
struct slot
{
    int r, c, num;
};
stack<slot> stk;
vector<vector<bool>> row_vst(9, vector<bool>(10, false));
vector<vector<bool>> col_vst(9, vector<bool>(10, false));
vector<vector<bool>> area_vst(9, vector<bool>(10, false));


void pv() {
    for (auto it : v)
    {
        for (auto it_ : it)
            cout << it_;
        cout << '\n';
    }
}
void visitSlot(slot st) {
    row_vst[st.r][st.num] = true;
    col_vst[st.c][st.num] = true;
    int area_no = (st.r / 3) * 3 + (st.c / 3);
    area_vst[area_no][st.num] = true;

    v[st.r][st.c] = st.num;
}

void unvisitSlot(slot st) {
    row_vst[st.r][st.num] = false;
    col_vst[st.c][st.num] = false;
    int area_no = (st.r / 3) * 3 + (st.c / 3);
    area_vst[area_no][st.num] = false;

    v[st.r][st.c] = 0;
}


bool isValid(slot st) {
    int area_no = (st.r / 3) * 3 + (st.c / 3);
    if (row_vst[st.r][st.num] || col_vst[st.c][st.num] || area_vst[area_no][st.num]) {
        return false;
    }
    return true;
}

void bt(int index, int num) {
    if (foundAns) return;
    int r = blanks[index].first, c = blanks[index].second;
    slot st({ r,c,num });
    visitSlot(st);

    if (index == blanks.size() - 1) {
        pv();
        foundAns = true;
        return;
    }

    r = blanks[index + 1].first, c = blanks[index + 1].second;
    for (int i = 1; i <= 9; i++) {
        slot st2 = { r,c,i };
        if (!isValid(st2))
            continue;
        else bt(index+1,i);
    }

    unvisitSlot(st);
}
int main() {
    IOS;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            char ch;
            cin >> ch;
            v[i][j] = ch - '0';
            if (!v[i][j]) blanks.push_back({ i,j });
            else {
                visitSlot({ i,j,v[i][j] });
            }
        }
    if (blanks.empty()) {
        pv();
        return 0;
    }
    int r = blanks[0].first, c = blanks[0].second;
    for (int i = 1; i <= 9; i++) {
        slot st = { r,c,i };
        if (!isValid(st))
            continue;
        else bt(0, i);
    }

    return 0;
}
