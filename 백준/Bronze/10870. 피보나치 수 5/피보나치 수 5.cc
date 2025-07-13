#include <iostream>
using namespace std;

int dp[45];

int main(){
    
    dp[0] = 0;
    dp[1] = 1;
    
    int n ; cin >> n;
    
    if(n==0){
        cout << 0;
        return 0;
    }
    
    if(n==1){
        cout << 1;
        return 0;
    }
    
    for(int i = 2 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << dp[n];
    
    return 0;
}
