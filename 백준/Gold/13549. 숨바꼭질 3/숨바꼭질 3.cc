#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dist[100002];
int n,k;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  cin >> n >> k;
    
  fill(dist, dist+100001,-1);
    
  dist[n] = 0;
    
  queue<int> Q;
  Q.push(n);
    
  while(dist[k] == -1){
    int cur = Q.front(); Q.pop();
      
    int teleport = cur * 2;
    bool teleport_p = true;
    if(teleport < 0 || teleport > 100000) teleport_p = false;
    if(dist[teleport] != -1)teleport_p = false;
      
      if(teleport_p){
          dist[teleport] = dist[cur];
          Q.push(teleport);
      }
    for(int nxt : {cur-1, cur+1}){
      if(nxt < 0 || nxt > 100000) continue;
      if(dist[nxt] != -1) continue;
        
      dist[nxt] = dist[cur]+1;
        
      Q.push(nxt);
    }
      
      
  }
  cout << dist[k];
}
