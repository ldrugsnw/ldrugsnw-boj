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
    int lastCheese = 0;

    while (true) {
        int cheeseCnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (board[i][j] == 1) cheeseCnt++;

        if (cheeseCnt == 0) break;
        lastCheese = cheeseCnt;

        memset(visited, false, sizeof(visited));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;

        vector<pair<int,int>> meltList;

        while (!q.empty()) {
            auto [y,x] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (visited[ny][nx]) continue;

                visited[ny][nx] = true;
                if (board[ny][nx] == 0) {
                    q.push({ny, nx});
                } else if (board[ny][nx] == 1) {
                    meltList.push_back({ny, nx});
                }
            }
        }

        for (auto [y,x] : meltList)
            board[y][x] = 0;

        time++;
    }

    cout << time << "\n" << lastCheese << "\n";

}


int main(){
    fastio;
    input();
    solve();
    return 0;
}
