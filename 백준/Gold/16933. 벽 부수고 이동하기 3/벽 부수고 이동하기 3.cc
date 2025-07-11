#include <iostream>
#include <queue>
using namespace std;

class info {
public:
    int board_value;
    int x, y;
    bool is_morning;
    int how_steps;
    int walls_broken;
    
    info() {
        board_value = 0;
        x = 0;
        y = 0;
        is_morning = true;
        how_steps = 0;
        walls_broken = 0;
    }
    
    info(int _x, int _y, int _steps, bool _is_morning, int _walls) {
        x = _x;
        y = _y;
        how_steps = _steps;
        is_morning = _is_morning;
        walls_broken = _walls;
    }
};

info board[1001][1001];
bool visited[1001][1001][2][11]; // [x][y][아침0/밤1][벽부순개수]

int dx[5] = {0, 0, -1, 1, 0}; // 상하좌우 + 제자리
int dy[5] = {1, -1, 0, 0, 0};

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    // 보드 초기화 및 좌표 설정
    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= M; j++) {
            board[i][j].board_value = line[j-1] - '0';
            board[i][j].x = i;
            board[i][j].y = j;
        }
    }
    
    queue<info> Q;
    
    // 시작점 설정
    info start(1, 1, 1, true, 0); // 아침부터 시작
    Q.push(start);
    visited[1][1][1][0] = true; // 아침=1, 벽부순개수=0
    
    while (!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        
        // 목표 지점 도달
        if (now.x == N && now.y == M) {
            cout << now.how_steps << endl;
            return 0;
        }
        
        for (int dir = 0; dir < 5; dir++) { // 제자리 포함 5방향
            int nx = now.x + dx[dir];
            int ny = now.y + dy[dir];
            
            // 범위 체크 (제자리는 항상 유효)
            if (nx < 1 || nx > N || ny < 1 || ny > M) {
                continue;
            }
            
            bool next_is_morning = !now.is_morning; // 시간 변경
            int morning_idx = next_is_morning ? 1 : 0;
            
            // 벽인 경우 (board_value == 1)
            if (board[nx][ny].board_value == 1) {
                // 벽을 부술 수 있는 경우 (현재가 아침이고 K > walls_broken)
                if (now.is_morning && now.walls_broken < K) {
                    int new_walls_broken = now.walls_broken + 1;
                    
                    if (!visited[nx][ny][morning_idx][new_walls_broken]) {
                        visited[nx][ny][morning_idx][new_walls_broken] = true;
                        info next(nx, ny, now.how_steps + 1, next_is_morning, new_walls_broken);
                        Q.push(next);
                    }
                }
                // 벽을 부술 수 없는 경우 - 제자리에서 대기만 가능
                else if (dir == 4) { // 제자리 대기
                    if (!visited[nx][ny][morning_idx][now.walls_broken]) {
                        visited[nx][ny][morning_idx][now.walls_broken] = true;
                        info next(nx, ny, now.how_steps + 1, next_is_morning, now.walls_broken);
                        Q.push(next);
                    }
                }
            }
            // 빈 공간인 경우 (board_value == 0)
            else {
                if (!visited[nx][ny][morning_idx][now.walls_broken]) {
                    visited[nx][ny][morning_idx][now.walls_broken] = true;
                    info next(nx, ny, now.how_steps + 1, next_is_morning, now.walls_broken);
                    Q.push(next);
                }
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}
