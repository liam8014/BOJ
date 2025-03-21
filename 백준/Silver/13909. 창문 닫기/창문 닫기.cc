#include <iostream>
#define SWS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
	SWS;
	int n;
	cin >> n;
	int i;
	for (i=1; i * i <= n; i++);
	cout << i-1;
	return 0;
}