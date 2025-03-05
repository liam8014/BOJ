#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	int count = 0, size=0;//count: case의 개수, size:배열의 크기
	string func, arr,tmp; //func: 실행할 함수들, arr: 주어진 배열, tmp : 배열 내 숫자 분리를 위한 임시 문자열
	bool isFront, isError; //isFront : 삭제방향이 앞이면 참 isError : Error가 감지되었으면 
	deque<int> dq;
	cin >> count;
	while (count-- > 0) {
		cin >> func >> size >> arr;
		tmp.clear();
		dq.clear();
		isFront = true;
		isError = false;
		for (int i = 0; i < arr.length(); i++) {
			if (arr[i] < 48 || arr[i] > 57) {//수가 아닌 값이 입력되었을 때
				if (!tmp.empty()) dq.push_back(stoi(tmp)); //tmp가 비어있지 않을 떄 tmp를 정수로 변환하여 dq에 입력
				tmp.clear(); //tmp 비우기
			}
			else { tmp.push_back(arr[i]); }//수가 입력되었을 때 tmp에 배열의 i번째 값 입력
		}
		for (int i = 0; i < func.length(); i++) {
			if (func[i] == 'D') {
				if (dq.empty()) {
					isError = true;
					break;
				}
				else {
					if (isFront) { dq.pop_front(); }
					else { dq.pop_back(); }
				}
			}
			else if (func[i] == 'R') {
				isFront = !isFront;
			}
		}
		if (isError) { cout << "error"; }
		else if (dq.empty()) { cout << "[]"; }
		else if (isFront) {
			cout << '[';
			for (int i = 0; i < dq.size() - 1; i++) {
				cout << dq[i] << ',';
			}
			cout << dq.back();
			cout << ']';
		}
		else if (!isFront) {
			cout << '[';
			for (int i = dq.size() - 1; i > 0; i--) {
				cout << dq[i] << ',';
			}
			cout << dq.front();
			cout << ']';
		}
		cout << "\n";
	}
	return 0;
}