#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    long long answer = 0;
    long long zeros = 0;
    map<pair<long long, long long>, long long> mp;
    
    for(int i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;
        
        if(x == 0 && y == 0){
            zeros++;
            continue;
        }
        
        if(x == 0){
            y = 1;
        } else if(y == 0){
            x = 1;
        } else {
            long long g = gcd(abs(x), abs(y));
            x /= g;
            y /= g;
        }
        
        answer += mp[{x, y}];
        mp[{-y, x}]++;
        mp[{y, -x}]++;
    }
    
    answer += zeros * (n - zeros) + zeros * (zeros - 1) / 2;
    
    cout << answer << "\n";
    
    return 0;
}