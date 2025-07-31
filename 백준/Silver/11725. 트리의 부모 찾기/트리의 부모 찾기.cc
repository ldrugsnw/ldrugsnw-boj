#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> adj[1000001];
int parent[1000001];

void dfs(int cur){
    for(int next : adj[cur]){
        if(parent[cur] == next) continue;
        parent[next] = cur;
        dfs(next);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0 ; i < n - 1 ; i++){
        int u,v;
        cin >> u >> v;
        
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    
    
    dfs(1);
    
    for(int i = 2; i <= n ; i++){
        cout << parent[i] << "\n";
    }
    
}
