/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15663                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ldrugsnw <boj.kr/u/ldrugsnw>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15663                          #+#        #+#      #+#    */
/*   Solved: 2025/07/11 14:10:38 by ldrugsnw      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 9

int arr[MAX];
bool isUsed[MAX];
int input_arr[MAX];
int before_[MAX];

int n, m;

void func(int cnt)
{
    if (cnt == m)
    {
        bool arr_before_same = true;
        for (int i = 0; i < m; i++)
        {
            if (arr[i] != before_[i])
            {
                arr_before_same = false;
            }
        }
        if (!arr_before_same)
        {
            for (int i = 0; i < m; i++)
            {
                cout << arr[i] << ' ';
            }

            for (int i = 0; i < m; i++)
            {
                before_[i] = arr[i];
            }
        
        cout << '\n';
        return;
        }
    }

    int usedNumber = 0;

    for (int i = 0; i < n; i++)
    {
        if (!isUsed[i] && usedNumber != input_arr[i])
        {
            arr[cnt] = input_arr[i];
            usedNumber = arr[cnt];
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

    for (int i = 0; i < n; i++)
    {
        cin >> input_arr[i];
    }

    sort(input_arr, input_arr + n);

    func(0);
}