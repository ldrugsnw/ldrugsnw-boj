#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int N, K;

void input(){
    cin >> N >> K;
}

void solve(){
    int ans = K;

    for(int i = 0 ; i < N-1 ; i++){
        ans /= 2;
    }
    
    cout << ans;
}

int main(){

    fastio;
    input();

    solve();

    return 0;
}
