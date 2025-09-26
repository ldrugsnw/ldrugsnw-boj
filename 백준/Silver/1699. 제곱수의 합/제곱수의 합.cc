#include <iostream>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int dp[100005];

int main() {
    fastio;
    
    int N; cin >> N;
    
    dp[0] = 0;
    
    for(int i = 1; i <= N; i++) {
        dp[i] = 1e9;
        for(int j = 1; j*j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j*j] + 1); // 어디에 제곱수를 얹을까 1, 4, 9 ... etc
        }
    }
    
    cout << dp[N];
    return 0;
}
