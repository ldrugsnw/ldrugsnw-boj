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

int dp[1001][4];
int R[1001];
int G[1001];
int B[1001];


int main(){
    int N;
    cin >> N;

    for(int i = 1 ; i <= N ;i++){
        cin >> R[i];
        cin >> G[i];
        cin >> B[i];
    }

    dp[1][0] = R[1];
    dp[1][1] = G[1];
    dp[1][2] = B[1];

    for(int i = 2 ; i <= N ; i++){
        dp[i][0] = min(dp[i-1][1] , dp[i-1][2]) + R[i];
        dp[i][1] = min(dp[i-1][0] , dp[i-1][2]) + G[i];
        dp[i][2] = min(dp[i-1][1] , dp[i-1][0]) + B[i];
    }

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]) << '\n';

    return 0;
}
