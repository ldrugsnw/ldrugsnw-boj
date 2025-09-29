#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

int N, M;

ll combination(int n, int r) {
    ll result = 1;
    for (int i = 1; i <= r; ++i) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

void input(){
    cin >> N >> M;
}

void solve(){
   cout << combination(M-1, N-1);
}

int main(){
    fastio;
    input();
    solve();
    return 0;
}
