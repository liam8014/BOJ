#include <iostream>
#include <string>
using namespace std;
long long calc(long long x, long long y);
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long x, y, n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		cout << calc(x, y) << "\n";
	}
	return 0;
}
long long calc(long long x, long long y)
{
	long long here = 0, speed = 0, dest = y - x, count = 0,expt = 0;
	while (here<dest){
		expt = here;
		expt += ((speed + 1) * (speed + 2)) / 2;
		if (expt <= dest){
			here += ++speed;
		}
		else if (expt - (speed+1) <= dest){
			here += speed;
		}
		else if (expt - (speed*2 + 1) <= dest){
			here += --speed;
		}
		count++;
	}
	return count;
}