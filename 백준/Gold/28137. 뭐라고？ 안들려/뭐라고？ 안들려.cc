#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

int main(){
    fastio;
    vector<int> order;
    int n;
    ll k;
    cin >> n >> k;
    
    map<ll, ll> M; // z, count

    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;

        ll z = y - k * x;

        M[z]++;
    }

    ll result = 0;

    for(auto m : M){
        ll n = m.second;
        result += n * (n-1);
    }

    cout << result << '\n';

    return 0;
}