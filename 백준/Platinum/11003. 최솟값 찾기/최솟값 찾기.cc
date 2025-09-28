#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int N, L;
vector<int> v;
deque<int> dq;

void input(){
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;

        v.push_back(tmp);
    }
}

void solve(){
    for(int i = 0 ; i < N; i++){
        while(!dq.empty() && dq.front() < i - L + 1){ // 범위가 벗어났다면 은퇴
            dq.pop_front();
        }

        while(!dq.empty() && v[dq.back()] >= v[i]){ // 방문한 애보다 크면 나오세요
            dq.pop_back();
        }
        
        dq.push_back(i);

        cout << v[dq.front()] << " ";
    }
}

int main(){

    fastio;
    input();
    solve();

    return 0;
}
