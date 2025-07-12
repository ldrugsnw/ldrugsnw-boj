/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2579                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ldrugsnw <boj.kr/u/ldrugsnw>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2579                           #+#        #+#      #+#    */
/*   Solved: 2025/07/13 01:38:34 by ldrugsnw      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int A[301];
int dp[301][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    
    for(int i = 1 ;i <= N; i++){
        cin >> A[i];
    }

    if(N==1){
        cout << A[1] << "\n";
        return 0;
    }

    dp[1][1] = A[1];
    dp[1][2] = 0;
    dp[2][1] = A[2];
    dp[2][2] = A[1] + A[2];

    for(int i = 3 ; i <= N ; i++){
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + A[i];
        dp[i][2] = dp[i-1][1] + A[i];
    }

    cout << max(dp[N][1], dp[N][2]) << "\n";

    return 0;

}