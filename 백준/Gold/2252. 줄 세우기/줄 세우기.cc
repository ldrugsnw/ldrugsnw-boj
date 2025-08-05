#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int v = 0;
    int e = 0;

    cin >> v >> e;

    vector<vector<int>> adj(v+1);
    vector<int> inDegree(v+1, 0);
    
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }
    
    //
    
    queue<int> q;
    for(int i = 1; i <= v; i++){
        if(inDegree[i] == 0){
            q.push(i);
            //cout << "큐에 추가: " << i << endl;
        }
    }
    
    //cout << "위상정렬 결과: ";
    while(!q.empty()){
        int now = q.front();
        cout << now << " ";
        q.pop();
        
        for(int next : adj[now]){
            inDegree[next]--;
            if(inDegree[next] == 0){
                q.push(next);
            }
        }
    }
    
    return 0;
}