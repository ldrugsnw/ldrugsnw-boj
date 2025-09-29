#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int N; string s;

void input(){
    cin >> N; cin >> s;
}

void solve(){
    for(int i = 0 ; i < N ; i ++){
        int diff_count = 0;

        for(int j = 0 ; j < i ; j++){
            if(s[j] != s[N-i+j]){
                diff_count++;
            }
        }

        if(diff_count == 1){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    fastio;
    input();
    solve();
    return 0;
}
