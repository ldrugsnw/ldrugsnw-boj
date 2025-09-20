#include <iostream>
#include <algorithm>
using namespace std;

#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)

bool C(int i, int j){
    return i < j;
}

int main(){
    
    fastio;
    
    int N;
    cin >> N;
    
    vector<pair<int, string>> p;
    
    for(int i = 0 ; i < N; i++){
        string title;
        int diff;
        cin >> title >> diff;
        
        p.push_back({diff, title});
    }
    
    sort(p.begin(), p.end());
    
    cout << p[0].second << endl;
    
    return 0;
}
