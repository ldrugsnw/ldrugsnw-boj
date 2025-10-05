#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pp pair<int, int>
#define ttt tuple<int, int, int>
#define tttt tuple<int, int, int, int>

// ------- Variable -------
int N;
set<int> sold;
// -----------------------


void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        sold.insert(x);
    }
}

void solve(){
    int answer = 1;
    while(sold.count(answer)){
        answer++;
    }
    cout << answer << '\n';
}


int main(){
    fastio;
    input();
    solve();
    return 0;
}
