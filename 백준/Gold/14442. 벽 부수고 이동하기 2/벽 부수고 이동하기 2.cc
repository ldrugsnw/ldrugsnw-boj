#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pp pair<int, int>
#define ttt tuple<int, int, int>
#define tttt tuple<int, int, int, int>

int N, M, K;
char board[1001][1001];
bool visited[1001][1001][11];

// 상 하 좌 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void input(){
    cin >> N >> M >> K;

    for(int i = 0 ; i < N ; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < M ; j++){
            board[i][j] = s[j];
        }
    }
}

/// i <- y , j <- x

int bfs() {
    queue<tuple<int, int, int, int>> q;

     if(N == 1 && M == 1){
        return 1;
    }

    q.push({0, 0, 0, 1}); 
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto [y, x, n_broken, dist] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if (ny == N - 1 && nx == M - 1) {
                return dist + 1;
            }

            if (board[ny][nx] == '0' && !visited[ny][nx][n_broken]) {
                visited[ny][nx][n_broken] = true;
                q.push({ny, nx, n_broken, dist + 1});
            }

            else if (board[ny][nx] == '1' && n_broken < K && !visited[ny][nx][n_broken+1]) {
                visited[ny][nx][n_broken + 1] = true; 
                q.push({ny, nx, n_broken + 1, dist + 1});
            }
        }
    }

    return -1;
}

int main(){
    fastio;
    input();

    cout << bfs() << '\n';
    
    return 0;
}
