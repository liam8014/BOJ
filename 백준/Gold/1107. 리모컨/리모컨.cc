#include <iostream>
using namespace std;
int getDigit(int num); //정수 자리수를 반환하는 함수
bool checkBroken(bool arr[], int ch);//고장난 버튼 포함 시 true
int getMove(bool arr[], int ch);//가장 가까운 미포함된 값
int main() {
	int ch = 100, target_ch = 0, broken = 0, move = 0; //broken : 고장난 버튼 수
	bool arr[10] = {false}; //버튼 고장여부 배열 0~9
	cin >> target_ch >> broken;
	for (int i = 0, j = 0; i < broken; i++) {
			cin >> j;
			arr[j] = true;
	}
	bool allBroken = true;//모든 버튼이 고장 시 true
	for (int i = 0; i < 10; i++) {if (!arr[i]) {allBroken = false;}}
	if (allBroken) {move = abs(target_ch - ch);}
	else {
		move = getMove(arr, target_ch);
	}
	cout << move;
	return 0;
}

int getDigit(int num) {
	int digit = 1;
	for (int i = 10; num >= i; i *= 10, digit++);
	return digit;
}

bool checkBroken(bool arr[], int ch) {
	do {//ch를 10으로 나누고, ch가 0보다 클 때 반복
		if (arr[ch % 10]) { return true; }//ch의 1의 자리 수가 고장된 버튼에 포함될 경우 true
		ch = ch / 10;
	} while (ch > 0);
	return false; //미포함될 경우 false
}
int getMove(bool arr[], int ch) {
	int diff, move = abs(100 - ch);
	for (diff = 0; checkBroken(arr, ch + diff) && ((ch - diff < 0) || checkBroken(arr, ch - diff)); diff++);//diff를 ch에서 가장 가까운 고장 미포함 값까지 1씩 늘림
	if (!checkBroken(arr, ch - diff)) {
		if (move > (getDigit(ch - diff) + diff)) {
			move = (getDigit(ch - diff) + diff);
		}
	}
	else {
		if (move > (getDigit(ch + diff) + diff)) {
			move = (getDigit(ch + diff) + diff);
		}
	}
	return move;
}