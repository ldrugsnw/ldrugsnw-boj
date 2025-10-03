#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pp pair<int, int>
#define ttt tuple<int, int, int>
#define tttt tuple<int, int, int, int>

// ------- Variable -------
int N, K; // N <- 보석 총 개수, K <= 가방 개수
vector<pp> jwely_info;
vector<int> bag_weight_info;
// -----------------------


void input(){
    cin >> N >> K; // N <- 보석 총 개수, K <= 가방 개수

    int M, V; // M <- 무게 , V <- 가격

    for(int i = 0 ; i < N ; i++){
        cin >> M >> V;
        jwely_info.push_back({M, V}); // 가격 우선 같아서 가격 먼저 넣었음
    }

    int C; // 각 가방에 넣을 수 있는 최대 무게
    for(int i = 0 ; i < K; i++){
        cin >> C;
        bag_weight_info.push_back(C);
    }
    
    sort(jwely_info.begin(), jwely_info.end());
    sort(bag_weight_info.begin(), bag_weight_info.end());
}

void solve(){
    ll total_price = 0;

    priority_queue<int> pq;

    int jwely_idx = 0;

    for(int i = 0 ; i < K; i++){
        int current_bag_capacity = bag_weight_info[i];

        while(jwely_idx < N && jwely_info[jwely_idx].first <= current_bag_capacity){
            pq.push(jwely_info[jwely_idx].second);
            jwely_idx++;
        }

        if(!pq.empty()){
            total_price+=pq.top();
            pq.pop();
        }
    }

    cout << total_price;
}


int main(){
    fastio;
    input();
    solve();
    return 0;
}
