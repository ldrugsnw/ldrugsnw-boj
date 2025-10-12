#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int H, W;
char grid[1001][1001];
int waveTime[1001][1001];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input(){
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> grid[i][j];
        }
    }
}

int countEmpty(int x, int y){
    int count = 0;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if(grid[nx][ny] == '.') count++;
    }
    return count;
}

void solve(){
    queue<pair<int, int>> q;
    memset(waveTime, 0, sizeof(waveTime));
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(grid[i][j] != '.'){
                int strength = grid[i][j] - '0';
                int emptyCount = countEmpty(i, j);
                
                if(emptyCount >= strength){
                    q.push({i, j});
                    waveTime[i][j] = 1;
                }
            }
        }
    }
    
    int maxWave = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        maxWave = max(maxWave, waveTime[x][y]);
        
        grid[x][y] = '.';
        
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(grid[nx][ny] == '.') continue;
            if(waveTime[nx][ny] > 0) continue; 
            
            int strength = grid[nx][ny] - '0';
            int emptyCount = countEmpty(nx, ny);
            
            if(emptyCount >= strength){
                waveTime[nx][ny] = waveTime[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    cout << maxWave << '\n';
}

int main(){
    fastio;
    input();
    solve();
    return 0;
}