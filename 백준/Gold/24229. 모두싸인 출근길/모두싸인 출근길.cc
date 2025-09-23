#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int main() {
    fastio;

    int N;
    cin >> N;

    vector<pair<int, int>> board;
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        board.push_back({start, end});
    }

    sort(board.begin(), board.end());

    vector<pair<int, int>> finals;
    if (N > 0) {
        int now_start = board[0].first;
        int now_end = board[0].second;
        for (int i = 1; i < board.size(); i++) {
            if (board[i].first <= now_end) {
                now_end = max(now_end, board[i].second);
            } else {
                finals.push_back({now_start, now_end});
                now_start = board[i].first;
                now_end = board[i].second;
            }
        }
        finals.push_back({now_start, now_end});
    }
    
    if (finals.empty() || finals[0].first != 0) {
        cout << 0 << endl;
        return 0;
    }

    queue<pair<int, int>> Q;
    vector<bool> visited(finals.size(), false);

    Q.push(finals[0]);
    visited[0] = true;

    int result = finals[0].second;
    int currentReach = finals[0].second;
    int seg_idx = 1;

    while (!Q.empty()) {
        auto [lastLanding, currentReach] = Q.front();
        Q.pop();

        int jumpDistance = currentReach - lastLanding;
        int jump_reach = currentReach + jumpDistance;

        currentReach = max(currentReach, jump_reach);

        while (seg_idx < finals.size() && finals[seg_idx].first <= currentReach) {
            if (!visited[seg_idx]) {
                Q.push(finals[seg_idx]);
                visited[seg_idx] = true;
                result = max(result, finals[seg_idx].second);

                currentReach = max(currentReach, finals[seg_idx].second);
            }
            seg_idx++;
        }
    }

    cout << result << endl;

    return 0;
}
