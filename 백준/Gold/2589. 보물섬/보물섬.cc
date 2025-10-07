#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pp pair<int, int>
#define ttt tuple<int, int, int>
#define tttt tuple<int, int, int, int>

// ------- Variable -------
int N, M;
vector<string> board;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
// -----------------------

void input(){
    cin >> N >> M;
    board.resize(N);
    for(int i = 0; i < N; i++){
        cin >> board[i];
    }
}

int bfs(int startX, int startY){
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;
    
    q.push({startX, startY});
    dist[startX][startY] = 0;
    
    int maxDist = 0;
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == 'W') continue;
            if(dist[nx][ny] != -1) continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            maxDist = max(maxDist, dist[nx][ny]);
            q.push({nx, ny});
        }
    }
    
    return maxDist;
}


void solve(){
    int answer = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == 'L'){
                int maxDist = bfs(i, j);
                answer = max(answer, maxDist);
            }
        }
    }
    
    cout << answer << '\n';
}


int main(){
    fastio;
    input();
    solve();
    return 0;
}
