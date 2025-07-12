/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1987                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ldrugsnw <boj.kr/u/ldrugsnw>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1987                           #+#        #+#      #+#    */
/*   Solved: 2025/07/11 22:41:05 by ldrugsnw      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

char board[20][20];
bool visited[26];

int R, C;
int answer;

void dfs(int x, int y, int ddd){
    
    bool canDoMore = false;
    
        for(int dir = 0 ; dir < 4; dir++){
            int now_x = x + dx[dir];
            int now_y = y + dy[dir];

            if(now_x < 0 || now_x >= R || now_y < 0 || now_y >= C){
                continue;
            }
            
            char nextAlphabet = board[now_x][now_y];

            if(visited[nextAlphabet - 'A']){
                continue;
            }
            
            canDoMore = true;
            
            visited[nextAlphabet - 'A'] = true;
            
            dfs(now_x, now_y, ddd + 1);
        
            visited[nextAlphabet - 'A'] = false;
        }
    
    if(!canDoMore){
        answer = max(answer, ddd);
        return;
    }
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    answer = 0;

    cin >> R >> C;

    for(int i = 0 ; i < R; i++){
        for(int j = 0 ; j < C ; j++){
            cin >> board[i][j];
        }
    }
    
    char nextAlpha = board[0][0];
    visited[nextAlpha - 'A'] = true;
    dfs(0,0,1);

    cout << answer << "\n";
    
   return 0;
}
