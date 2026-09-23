#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int convert(string str){
    int hh = stoi(str.substr(0,2)), mm = stoi(str.substr(3,2));
    return hh * 60 + mm;
}
struct node{
    string name;
    int sTime;
    int rTime;
    
    bool operator>(const node& nd) const {
        return sTime>nd.sTime; 
    }
};
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<node, vector<node>, greater<node> > pq;

    for( auto it : plans ) {
        pq.push({it[0], convert(it[1]), stoi(it[2])});
    }
    
    int curTime = pq.top().sTime;
    stack<node> stk;
    
    while (!pq.empty()) {
        node currentTask = pq.top();
        pq.pop();

        if (curTime < currentTask.sTime) {
            curTime = currentTask.sTime;
        }
        
        stk.push(currentTask);
        
        if (pq.empty()) {
            break;
        }
        
        node nextTask = pq.top();
        
        while (!stk.empty()) {
            if (curTime + stk.top().rTime <= nextTask.sTime) {
                curTime += stk.top().rTime;
                answer.push_back(stk.top().name);
                stk.pop();
            } else {
                stk.top().rTime -= (nextTask.sTime - curTime);
                curTime = nextTask.sTime;
                break;
            }
        }
    }

    while (!stk.empty()) {
        answer.push_back(stk.top().name);
        stk.pop();
    }
    
    return answer;
}
