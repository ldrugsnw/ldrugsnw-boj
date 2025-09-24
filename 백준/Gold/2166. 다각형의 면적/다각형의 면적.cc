#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

int main() {
    fastio;
    
    int n;
    cin >> n;

    vector<pair<ll, ll>> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    ll sum = 0;
    
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        
        sum += points[i].first * points[next].second;
        sum -= points[next].first * points[i].second;
    }
    
    double area = abs(sum) / 2.0;
    
    cout << fixed << setprecision(1) << area << endl;
    
    
    return 0;
}
