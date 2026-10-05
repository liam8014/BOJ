#include <string>
#include <vector>
#include <queue>

using namespace std;

int numTime(string time){
    int hh = stoi( time.substr(0,2) ),
        mm = stoi( time.substr(3,2) );
    return hh * 60 + mm;
}

string strTime(int time){
    string hh = to_string( time/60 ),
        mm = to_string( time%60 );

    if(hh.length()==1)
        hh = '0' + hh;

    if(mm.length()==1)
        mm = '0' + mm;
    
    return hh + ':' + mm;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<int,vector<int>,greater<int>> pq;
    int curTime = numTime("09:00");
    int maxTime = curTime + (t * (n-1));

    for(const string& time : timetable){
        int inTime = numTime(time);
        if( inTime <= maxTime )
            pq.push(inTime);
    }

    while (curTime <= maxTime) {
        int cnt = 0, lastCrew = -1;

        for(int i = 0;i<m;i++){
            if( pq.empty() )
                break;
            
            int crew = pq.top();
            if(crew <= curTime){
                cnt++;
                lastCrew = crew;
                pq.pop();
            }
        }
        
        if(cnt == m) {
            if( lastCrew > 0 )
                answer = strTime(lastCrew-1);
        } else {
            answer = strTime(curTime);
        }
        curTime += t;
    }
    return answer;
}