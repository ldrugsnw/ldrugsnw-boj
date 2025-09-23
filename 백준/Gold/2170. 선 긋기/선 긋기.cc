#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int main(){
    fastio;
    
    int N; cin >> N;
    
    vector<pair<int, int>> board;
    
    for(int i = 0 ; i < N ; i++){
        int start, end;
        cin >> start >> end;
        
        board.push_back({start, end});
    }
    
    sort(board.begin(), board.end());
    
    int now_start = board[0].first;
    int now_end = board[0].second;
    
    int result = 0;
    
    for(int i = 1 ; i < board.size(); i++){
        
        if(board[i].first <= now_end){ // 겹친다!!!!!!
            now_end = max(now_end, board[i].second);
        }
        
        else{ // 안 겹친다!!
            result += (now_end - now_start);
            now_start = board[i].first;
            now_end = board[i].second;
        }
    }
    
    result += (now_end - now_start);
    
    cout << result << endl;
    
    return 0;
}
