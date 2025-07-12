/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1149                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ldrugsnw <boj.kr/u/ldrugsnw>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1149                           #+#        #+#      #+#    */
/*   Solved: 2025/07/13 02:03:14 by ldrugsnw      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int dp[3][100001];
int sticker[3][100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    int T; cin >> T;
    
    while(T--){
        int n; cin >> n;
        
        
        for(int i = 1 ;i <= n ;i++){
            cin >> sticker[1][i];
        }
        
        for(int i = 1 ;i <= n ;i++){
            cin >> sticker[2][i];
        }
        
        if(n == 1){
            cout << max(sticker[1][1], sticker[2][1]) << '\n';
            continue;
        }
        

        dp[1][1] = sticker[1][1];
        dp[2][1] = sticker[2][1];
        dp[1][2] = sticker[1][2] + dp[2][1];
        dp[2][2] = sticker[2][2] + dp[1][1];
        
        for(int i = 3 ; i <= n ; i++){
            dp[1][i] = max(dp[2][i-1], dp[2][i-2]) + sticker[1][i];
            dp[2][i] = max(dp[1][i-1], dp[1][i-2]) + sticker[2][i];
        }
        
        cout << max(dp[1][n] , dp[2][n]) << '\n';
    }
    
    return 0;
}
