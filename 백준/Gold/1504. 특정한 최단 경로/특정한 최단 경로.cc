#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

const int INF = 1e9+10;
vector<pair<int,int>> adj[20005];
int v, e;

vector<int> dijkstra(int st){
    vector<int> dist(v+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[st] = 0;
    pq.push({0, st});
    
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(dist[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(dist[nxt.Y] > dist[cur.Y] + nxt.X){
                dist[nxt.Y] = dist[cur.Y] + nxt.X;
                pq.push({dist[nxt.Y], nxt.Y});
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    int via1, via2;
    cin >> via1 >> via2;

    int st = 1;
    int end = v;

    vector<int> distSt = dijkstra(st);
    vector<int> distV1 = dijkstra(via1);
    vector<int> distV2 = dijkstra(via2);

    long long path1 = (long long)distSt[via1] + distV1[via2] + distV2[end];

    long long path2 = (long long)distSt[via2] + distV2[via1] + distV1[end];

    long long ans = min(path1, path2);

    if(ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

