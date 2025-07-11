/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11441                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ldrugsnw <boj.kr/u/ldrugsnw>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11441                          #+#        #+#      #+#    */
/*   Solved: 2025/07/11 15:27:43 by ldrugsnw      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int arr[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    for(int i = 1 ; i <= N ;i++){
        int a;
        cin >> a;
        arr[i] = a + arr[i-1];
    }


    int M; cin >> M;

    for(int i = 0 ;i < M; i++){
        int w, v;
        cin >> w >> v;
        cout << arr[v] - arr[w-1] << "\n";
    }

    return 0;
}
