#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int N, R, Q;

bool visited[100001];
vector<int> tree[100001];
vector<int> query;
int dp[100001];

void input(){
    int u, v;
    
    cin >> N >> R >> Q;

    for(int i = 0 ; i < N-1 ; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    int q;
    
    for(int i = 0 ; i < Q ; i++){
        cin >> q;
        query.push_back(q);
    }
    
    for(int i = 0 ; i <= N ; i++){
        dp[i] = 1; // leaf node 1 반환을 위해
    }
}

int dfs(int now){
    visited[now] = true;
    
    for(int i = 0 ; i < tree[now].size(); i++){
        // now와 연결되어 있는 애들 싹 다 조사
        int next = tree[now][i];
        
        if(visited[next]) continue;
        
        dp[now] += dfs(next);
    }
    
    return dp[now]; // 맨 말단에 있는 애들이 1 return
    
}

int main() {
    fastio;
    
    input();
    dfs(R);
    
    for(int q : query){
        cout << dp[q] << '\n';
    }
    
    return 0;
}
