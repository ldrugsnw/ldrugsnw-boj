#include <iostream>
#include <queue>
using namespace std;

int dist[100001];
int cnt[100001];  // 해당 위치에 도달하는 방법의 수
int subin, sebin;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   cin >> subin >> sebin;
   
   fill(dist, dist + 100001, -1);
   
   dist[subin] = 0;
   cnt[subin] = 1; 
   
   queue<int> Q;
   Q.push(subin);
   
   while (!Q.empty()) {
       int cur = Q.front();
       Q.pop();
       
       for (int nv : {cur + 1, cur - 1, cur * 2}) {
           if (nv < 0 || nv > 100000) continue;
           
           if (dist[nv] == -1) {  
               dist[nv] = dist[cur] + 1;
               cnt[nv] = cnt[cur];
               Q.push(nv);
           }
           else if (dist[nv] == dist[cur] + 1) {  
               cnt[nv] += cnt[cur];
           }
       }
   }
   
   cout << dist[sebin] << '\n';
   cout << cnt[sebin] << '\n';
   
   return 0;
}