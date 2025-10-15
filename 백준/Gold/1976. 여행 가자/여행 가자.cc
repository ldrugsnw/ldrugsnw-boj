#include <iostream>
#include <vector>
using namespace std;

vector<int> p(201, -1);

int find(int x){
    if(p[x] < 0){
        return x;
    }
    return p[x] = find(p[x]);
}

void uni(int u, int v){
    u = find(u);
    v = find(v);
    
    if(u == v){
        return;
    }
    
    if(p[v] < p[u]){
        swap(u, v);
    }
    
    if(p[u] == p[v]){
        p[u]--;
    }
    
    p[v] = u;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int connected;
            cin >> connected;
            if(connected == 1){
                uni(i, j);
            }
        }
    }
    
    vector<int> plan(m);
    for(int i = 0; i < m; i++){
        cin >> plan[i];
    }
    
    bool possible = true;
    int root = find(plan[0]);
    
    for(int i = 1; i < m; i++){
        if(find(plan[i]) != root){
            possible = false;
            break;
        }
    }
    
    if(possible){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}