#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pp pair<int, int>
#define ttt tuple<int, int, int>
#define tttt tuple<int, int, int, int>

// ------- Variable -------
int N, M;
int board[105][105];
int contact[105][105];
bool visited[105][105];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
// -----------------------


void input(){
    cin >> N >> M;
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
}

void solve(){
    int time = 0;
    while (true) {
        memset(visited, false, sizeof(visited));
        memset(contact, 0, sizeof(contact));

        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

                if (board[ny][nx] == 0 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                } 
                else if (board[ny][nx] == 1) {
                    contact[ny][nx]++; 
                }
            }
        }

        vector<pp> meltList;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (board[i][j] == 1 && contact[i][j] >= 2)
                    meltList.push_back({i, j});

        if (meltList.empty()) break;

        for (auto [y,x] : meltList)
            board[y][x] = 0;

        time++;
    }

    cout << time << "\n";

}


int main(){
    fastio;
    input();
    solve();
    return 0;
}
