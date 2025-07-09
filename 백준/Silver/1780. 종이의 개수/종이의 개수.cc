/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1780                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ldrugsnw <boj.kr/u/ldrugsnw>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1780                           #+#        #+#      #+#    */
/*   Solved: 2025/07/09 14:07:46 by ldrugsnw      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int board[2200][2200];

int cnt[3];

bool check(int x, int y, int size){

    for(int i = x ; i < x+size; i++){
        for(int j = y ; j < y+size ; j++){
            if(board[x][y] != board[i][j]){
                return false;          
            }        
        }
    }

    return true;
}

void solve(int x, int y, int size){

    if(check(x, y, size)){
        cnt[board[x][y] + 1] += 1;
        return;
    }

    size = size / 3;
    
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ;j < 3 ;j++){
            solve(x + i*size, y + j*size, size);
        }
    }

}

int main(){
    int N; cin >> N;

    for(int i = 0; i < N ;i ++){
        for(int j = 0 ; j < N ; j++){
            board[i][j] = 0;
        }
    }

    for(int i = 0; i < 3 ;i ++){
        cnt[i] = 0;
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> board[i][j];
        }
    }

    solve(0,0,N);

    for(int a : cnt){
        cout << a << endl;
    }
}