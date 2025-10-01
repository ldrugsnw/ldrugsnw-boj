#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> board;
vector<vector<int>> dist;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int bfs(int sy,int sx) {
    deque<tuple<int,int,int>> q; 
    q.push_back({sy,sx,0});
    dist[sy][sx]=0;

    while(!q.empty()){
        auto [y,x,d] = q.front(); q.pop_front();
        if(board[y][x]=='K') return d;

        for(int dir=0; dir<4; dir++){
            int ny=y, nx=x;
            while(true){
                ny+=dy[dir]; nx+=dx[dir];
                if(ny<0||ny>=N||nx<0||nx>=N) break;
                if(board[ny][nx]=='B') break;

                if(d>=dist[ny][nx]) break;
                if(d+1 < dist[ny][nx]){
                    dist[ny][nx]=d+1;
                    q.push_back({ny,nx,d+1});
                }
                if(board[ny][nx]=='K'||board[ny][nx]=='W') break;
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    board.resize(N);
    dist.assign(N, vector<int>(N, INT_MAX));

    int sy,sx;
    for(int i=0;i<N;i++){
        cin >> board[i];
        for(int j=0;j<N;j++){
            if(board[i][j]=='R'){
                sy=i; sx=j;
                board[i][j]='.';
            }
        }
    }

    cout << bfs(sy,sx) << "\n";
}
