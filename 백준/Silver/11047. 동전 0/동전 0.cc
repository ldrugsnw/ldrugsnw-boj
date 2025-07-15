#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int main(){
    int N;
    cin >> N;
    
    int K;
    cin >> K;
    
    vector<int> coins;
    
    for(int i = 0 ; i < N ; i++){
        int coin; cin >> coin;
        coins.push_back(coin);
    }
    
    int result = 0;
        
    for(int i = N - 1 ; i >= 0 ; i--){
        while(K >= coins[i]){
            K -= coins[i];
            result++;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
