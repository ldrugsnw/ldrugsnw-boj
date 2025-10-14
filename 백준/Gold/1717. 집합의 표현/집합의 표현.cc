#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define ll long long

vector<int> p(1000001, -1);
int n, m;

int find(int x){
    if(p[x] < 0){
        return x; // -1이면 x가 root...
    }
    return p[x] = find(p[x]);
}

// Union by Rank
void uni(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v){
        return;
    }

    if(p[v] < p[u]){
        swap(u, v);
    } // 이 if때문에 항상 u가 루트가 될 아이임!

    if(p[u] == p[v]){ // 랭크가 같다면 u, v
        p[u]--;
    }

    p[v] = u; // v의 parent는 u 입니다.
}

// 

void input(){
    cin >> n >> m;
}

void solve(){
    for(int i = 0 ; i < m ; i++){
        int q;
        cin >> q;

        int a, b;
        cin >> a >> b;

        if(q == 0){ // union
            uni(a, b);
        }

        else if(q == 1){ // find
            if(find(a) == find(b)){
                cout << "YES\n";
            }
            
            else{
                cout << "NO\n";
            }
        }
    }
}

int main(){
    fastio;
    input();
    solve();
    return 0;
}