#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N;
char board[101][101];
bool visited[101][101];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int x, int y){
    queue<pair<int, int>> Q;
    
    Q.push({x, y});
    visited[x][y] = true;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        
        for(int dir = 0 ; dir < 4 ; dir++){
            int now_x = cur.first + dx[dir];
            int now_y = cur.second + dy[dir];
            
            if(now_x < 0 || now_x >= N || now_y < 0 || now_y >= N){
                continue;
            }
            
            if(visited[now_x][now_y] == 1 || board[x][y] != board[now_x][now_y]){
                continue;
            }
            
            visited[now_x][now_y] = true;
            Q.push({now_x, now_y});
        }
    }
}

int getArea(){
    int cnt = 0;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(!visited[i][j]){
                cnt++;
                bfs(i, j);
            }
        }
    }
    
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> board[i][j];
        }
    }
    
    // R, G, B
    int normal = getArea();
    
    
    // ...
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            visited[i][j] = false;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (board[i][j] == 'G')
            board[i][j] = 'R';
        }
      }
    
    // RG, B
    
    int saekMaeng = getArea();
    cout << normal << " " << saekMaeng << '\n';
    
    return 0;
}
