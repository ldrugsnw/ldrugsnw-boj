#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
#define ll long long
#define pp pair<int, int>

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    
    vector<ll> v;
    queue<ll> q;
    
    for(int i = 0; i <= 9; i++){
        q.push(i);
        v.push_back(i);
    }
    
    while(!q.empty()){
        ll num = q.front();
        q.pop();
        
        int last = num % 10;
        
        for(int i = 0; i < last; i++){
            ll newnum = num * 10 + i;
            q.push(newnum);
            v.push_back(newnum);
        }
    }
    
    if(N >= v.size()){
        cout << -1 << '\n';
    } else {
        cout << v[N] << '\n';
    }
    
    return 0;
}