#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define ll long long

vector<int> p(1000001, -1);
int n, k;

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


int main(){
    fastio;

    int t; cin >> t;

    for(int tc = 1 ; tc <= t ; tc++){
        int n, k;
        cin >> n >> k;

        cout << "Scenario " << tc << ":\n";

        fill(p.begin() + 1, p.begin() + n + 1 , -1);

        while(k--){
            int a, b;
            cin >> a >> b;
            uni(a, b);
        }

        int m;
        cin >> m;

        while(m--){
            int u, v;
            cin >> u >> v;

            cout << (find(u) == find(v)) << '\n';
        }

        cout << '\n';
    }
    return 0;
}