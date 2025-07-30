#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

bool visited_bfs[1001];
bool visited_dfs[1001];

int n,m;
int first_vertex;

vector<int> v[1001];

void dfs(int cur){
    visited_dfs[cur] = true;
    cout << cur << " ";
    for(auto next : v[cur]){
        if(visited_dfs[next]) continue;
        dfs(next);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> first_vertex;

    for(int i = 0 ; i < m ; i++){
        int vv, ee;
        cin >> vv >> ee;

        v[vv].push_back(ee);
        v[ee].push_back(vv);
    }
    
    for(int i = 1 ; i <= n ; i++){
        sort(v[i].begin() ,v[i].end());
    }
    
    //cout << "DFS : ";
    dfs(first_vertex);
    
    cout << '\n';

    queue<int> q;
    
    // bfs start
    
    q.push(first_vertex);
    visited_bfs[first_vertex] = true;
    
    //cout << "BFS : ";

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        cout << cur << " ";
        
        for(auto next : v[cur]){
            if(visited_bfs[next])continue;
            q.push(next);
            visited_bfs[next] = true;
        }
    }
    


    return 0;
}
