#include <iostream>
#include <algorithm>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
struct point {
    long long  x, y;
};

int crossCheck(point a, point b, point c) {
    if ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) == 0)
        return 0;
    else if ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) > 0)
        return 1;
    else
        return -1;
}
int main() {
    IOS;
    point p1, p2, p3, p4;
    bool ans;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;
    long long c123 = crossCheck(p1, p2, p3), c124 = crossCheck(p1, p2, p4),
        c341 = crossCheck(p3, p4, p1), c342 = crossCheck(p3, p4, p2),
        L1_CW = c123 * c124, L2_CW = c341 * c342;
    if (L1_CW == 0 && L2_CW == 0) {
        long long L1_max, L2_max, L1_min, L2_min;
        if (p1.x ==  p2.x) {
            L1_max = max(p1.y, p2.y),
            L2_max = max(p3.y, p4.y),
            L1_min = min(p1.y, p2.y),
            L2_min = min(p3.y, p4.y);
        }
        else {
            L1_max = max(p1.x, p2.x),
            L2_max = max(p3.x, p4.x),
            L1_min = min(p1.x, p2.x),
            L2_min = min(p3.x, p4.x);
        }
        if (L1_max >= L2_min && L2_max >= L1_min) {
            ans = true;
        }
        else {
            ans = false;
        }
    }
    else
    {
        ans = L1_CW <= 0 && L2_CW <= 0;
    }
    cout << (ans ? 1 : 0);
    return 0;
}