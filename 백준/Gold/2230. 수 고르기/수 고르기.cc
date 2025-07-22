#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int result = 2000000001;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> v;
    
    for(int i = 0 ; i < n ; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    
    int en = 0;
    
    for(int st = 0 ; st < n ; st++){
        while(en < n && v[en] - v[st] < m) en++;
        if(en == n) break;
        result = min(result, v[en] - v[st]);
    }
    
    cout << result;
    
    return 0;
}
