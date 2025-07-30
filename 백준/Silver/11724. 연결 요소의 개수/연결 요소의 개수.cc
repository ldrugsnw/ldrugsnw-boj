#include <iostream>
using namespace std;
#include <vector>
#include <queue>

bool visited[1001];

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> v(n+1);

    for(int i = 0 ; i < m ; i++){
        int vv, ee;
        cin >> vv >> ee;

        v[vv].push_back(ee);
        v[ee].push_back(vv);
    }

    queue<int> q;

    int answer = 0;

    for(int i = 1 ; i <= n ; i++){
        if(visited[i]){
            continue;
        }

        visited[i] = true;
        q.push(i);
        answer++;
        
        // bfs start

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(auto nxt : v[cur]){
                if(visited[nxt])continue;

                q.push(nxt);
                visited[nxt] = true;
            }
        }
    }

    cout << answer;

    return 0;
}
