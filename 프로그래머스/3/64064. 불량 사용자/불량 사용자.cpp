/*
각 경우의 수에 걸릴 수 있는 개수의 종류?
하나의 아이디가 두개의 제재 ID에 해당할 수도 있음

fr*d*, *rodo -> frodo 2번!
방문처리를 비트마스킹으로 구현할 수 있음 최대 8개의 id니까


*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
vector<string> U, B;
vector<bool> vst(1 << 8, false);
bool isSame(string& s, string& bs){
    if(bs.length() != s.length())
        return false;
    for(int i =0;i<s.length();i++){
        if(bs[i] != '*' && bs[i] != s[i])
            return false;

    }
    return true;
}
void dfs(int u_idx, int b_idx, int _vst){
    _vst |= (1 << u_idx);
    if(b_idx < B.size()-1){
        for(int i = 0; i< U.size();i++){
            if(!(_vst &1 <<i) && isSame(U[i], B[b_idx+1])){
                dfs(i,b_idx+1,_vst);
            }
        }
    }
    else if(b_idx == B.size()-1){
        if(!vst[_vst]){
            vst[_vst] = true;
            answer++;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    U = user_id, B=banned_id;
    for(int i =0;i<U.size();i++){
        if(isSame(U[i],B[0])){
            dfs(i,0,0);
        }
    }
    return answer;
}