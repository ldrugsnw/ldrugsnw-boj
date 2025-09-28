#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
int dp[46];int N;

// 45
// dp[45] 1134903170
// dp[44] 701408733

void fill_fibo(){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2 ; i <= 45 ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
}

void solve(int Q){

    stack<int> answer;
    
    while(1){
        int idx = upper_bound(dp, dp+46, Q) - dp-1;

        if(idx <= 0){
            break;
        }
        
        int D = dp[idx];
        answer.push(D);
        Q -= D;
    }
    
    while(!answer.empty()){
        cout << answer.top() << " ";
        answer.pop();
    }

    cout << endl;

}

int main(){

    fill_fibo();

    cin >> N;

    for(int i = 0 ; i < N; i++){
        int Q; cin >> Q;

        solve(Q);
    }

    return 0;
}
