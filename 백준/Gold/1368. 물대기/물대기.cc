// 프림 알고리즘 이용

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long;

int v, e;

vector<pair<int, int>> adj[10005];
// ( 간선의 비용, 정점 번호 )

bool check[10005];
int cnt = 0;

int main() {
    fastio;
    
    cin >> v; // vertex 개수
    
    for(int i = 1 ; i <= v ; i++){
        int cost;
        cin >> cost;
        
        adj[i].push_back({cost, v+1});
        adj[v+1].push_back({cost, i});
    }
    
    
    for(int i = 1 ; i <= v ; i++){
        for(int j = 1 ; j <= v ; j++){
            int cost; cin >> cost;
            
            if(i >= j) continue;
            
            adj[i].push_back({cost, j});
            adj[j].push_back({cost, i});
        }
        
    }
    
    v++;
    
    // {cost, 정점1, 정점2} -> 최소 힙
    priority_queue<tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>> > pq;
    
    check[1] = 1;
    
    int answer = 0;
    
    for(auto nxt : adj[1]){
        pq.push({nxt.first, 1, nxt.second});
    }
    
    while(cnt < v-1){
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        
        if(check[b]) continue;
        //cout << cost << ' ' << a << ' ' << b << '\n';
        check[b] = 1;
        answer += cost;
        cnt++;
        
        for(auto nxt : adj[b]){
            if(!check[nxt.second]){
                pq.push({nxt.first, b, nxt.second});
            }
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}
