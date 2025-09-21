#include <iostream>
#include <algorithm>
using namespace std;

#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)

int main(){
    fastio;
    
    int N;
    cin >> N;
    
    vector<int> v;
    
    int tmp = 0;
    for(int i = 0 ; i < N ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    int t;
    cin >> t;
    
    int s;
    for(int i = 0; i < t; i++){
        cin >> s;
        cout << upper_bound(v.begin(), v.end(), s) - lower_bound(v.begin(), v.end(), s) << " ";
    }
    
    return 0;
}
