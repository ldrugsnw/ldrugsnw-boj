/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15654                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ldrugsnw <boj.kr/u/ldrugsnw>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15654                          #+#        #+#      #+#    */
/*   Solved: 2025/07/10 14:26:46 by ldrugsnw      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 9

int arr[MAX];
bool isUsed[MAX];
int input_arr[MAX];

int n, m;

void func(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)  // 0부터 n-1까지
    {
        if (!isUsed[i])
        {
            arr[cnt] = input_arr[i];
            isUsed[i] = true;
            func(cnt + 1);
            isUsed[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> input_arr[i];
    }

    sort(input_arr, input_arr + n);

    func(0);
}