#include <iostream>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll res = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

int main() {
    fastio;
    
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    ll ccw1 = ccw(x1, y1, x2, y2, x3, y3);
    ll ccw2 = ccw(x1, y1, x2, y2, x4, y4);
    ll ccw3 = ccw(x3, y3, x4, y4, x1, y1);
    ll ccw4 = ccw(x3, y3, x4, y4, x2, y2);
    
    if (ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0) { // 겹쳐요?
        if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2) &&
            min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2)) {
            cout << 1;
            return 0;
        } else {
            cout << 0;
            return 0;
        }
    }
    else if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) {
        cout << 1;
    } else {
        cout << 0;
    }
    
    return 0;
}
