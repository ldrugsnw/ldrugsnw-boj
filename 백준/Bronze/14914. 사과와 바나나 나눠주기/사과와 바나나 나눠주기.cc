#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
int a, b;
void input(){
    cin >> a >> b;
}

void solve(){
    for(int i = 1 ; i <= min(a, b) ; i++){
        if((a%i == 0) && (b%i == 0)){
            cout << i << " " << a/i << " " << b/i << '\n';
        }
    }
}

int main(){
    fastio;
    input();
    solve();
    return 0;
}
