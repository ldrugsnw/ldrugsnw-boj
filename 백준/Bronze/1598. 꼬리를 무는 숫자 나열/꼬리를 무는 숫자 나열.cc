#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
using pp = pair<int,int>;

const ll INF = (ll)1e18;
#define MAX 1e9;
const int MOD = 1000000007;

int main(){
    fastio;

    int a, b;
    cin >> a >> b;

    int mn = min(a, b);
    int mx = max(a, b);

    int c = (mx-1) / 4 - (mn-1) / 4;
    int d = (mx-1) % 4 - (mn-1) % 4;

    cout << abs(c) + abs(d);
    

    return 0;
}