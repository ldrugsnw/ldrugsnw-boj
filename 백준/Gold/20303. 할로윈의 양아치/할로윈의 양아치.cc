#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
#define ll long long
#define pp pair<int, int>


int candy[30001];
vector<int> adj[30001];
vector<pp> babies; // sum, N
bool visited[30001];
int dp[30001]; // dp[k] => k명 미만으로 얻을 수 있는 최대 사탕
//냅색!!!!!


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, K; cin >> N >> M >> K;
    // N : 친구 명수, M : 관계 개수, K : 이만큼 뺏으면 더 못 뺐음..

    for(int i = 1 ; i <= N ; i++){
        int c; cin >> c;
        candy[i] = c;
    }

    for(int i = 0 ; i < M ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1 ; i <= N ; i++){
        if(visited[i]){
            continue;
        }
        queue<int> q;
        q.push(i);
        visited[i] = true;

        int count = 0;
        int sum = 0;

        while(!q.empty()){
            int cur = q.front();
            q.pop();;
            
            sum += candy[cur];
            count++;

            for(int nxt : adj[cur]){
                if(!visited[nxt]){
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        babies.push_back({sum, count});
    }

    for(auto [sum, count] : babies){
        for(int k = K-1 ; k >= count; k--){
            dp[k] = max(dp[k], // 그대로
                    dp[k-count] + sum); // 이거 뽑아버리기
        }
    }   
    

    cout << *max_element(dp, dp+K) << '\n';
    
    return 0;
}   
