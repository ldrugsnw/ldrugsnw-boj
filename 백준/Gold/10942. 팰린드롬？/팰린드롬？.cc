#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

int main() {
    fastio;
    
    int N;
    cin >> N;
    
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    vector<vector<bool>> dp(N+1, vector<bool>(N+1, false));
    
    
    for (int i = 1; i <= N; i++) { // size == 1
        dp[i][i] = true;
    }
    
    for (int i = 1; i < N; i++) { // size == 2
        if (arr[i] == arr[i + 1]) {
            dp[i][i + 1] = true;
        }
    }
    
    
    for(int len = 3; len <= N ; len++){
        for(int i = 1 ; i <= N - len + 1 ; i++){
            int j = i + len - 1;
            
            if(arr[i] == arr[j] && dp[i+1][j-1]){
                dp[i][j] = true;
            }
        }
        
    }
    
    int M;
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        
        if(dp[S][E]){
            cout << 1 << '\n';
        }
        
        else{
            cout << 0 << '\n';
        }
    }
    
    return 0;
}
