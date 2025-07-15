#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> V;
    
    for(int i = 0 ; i < N ; i++){
        int a; cin >> a;
        V.push_back(a);
    }
    
    sort(V.begin(), V.end());
    
    int result = 0;
    
    for(int i = 0 ; i < N ; i++){
        result = max(result, (N-i) * V[i]);
    }
    
    cout << result;
    
    return 0;
}
