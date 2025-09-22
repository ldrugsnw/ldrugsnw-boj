#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

ll N, M; // N <- 심사대 개수, M <- 친구 명수

bool check(vector<ll> & passes, ll mid){ // mid <- 현재 보고있는 시간
    
    ll frCount = 0;
    
    for(ll pass : passes){
        
        frCount += mid / pass;
        
        if(frCount >= M) return true;
    }
    
    return frCount >= M;
}

int main(){
    fastio;
    
    cin >> N >> M;
    
    vector<ll> Tk;
    
    int tmp;

    for(int i = 0 ; i < N ; i++){
        cin >> tmp;
        Tk.push_back(tmp);
    }
    
    sort(Tk.begin(), Tk.end());
    
    ll left = 1;
    
    ll right = Tk[0] * M;
    
    for(ll s : Tk){
        right += s;
    }
    
    ll result = 0;
    
    while(left <= right){
        ll mid = (left + right) / 2;
        
        if(check(Tk, mid)){
            result = mid;
            right = mid - 1;
        }
        
        else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
