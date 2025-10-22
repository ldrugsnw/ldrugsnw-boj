#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
#define ll long long
#define pp pair<int, int>

int C, N;
int cost[21];
int client[1001];
int dp[1000000];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> C >> N;

    for(int i = 1 ; i <= N; i++){
        cin >> cost[i] >> client[i];
    }

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= 100000 ; j++){
            if(j - cost[i] >= 0){
                dp[j] = max(dp[j], dp[j-cost[i]] + client[i]);
            }
        }
    }

    for(int i = 1; i <= 100000; i++){
        if(dp[i] >= C){
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}   
