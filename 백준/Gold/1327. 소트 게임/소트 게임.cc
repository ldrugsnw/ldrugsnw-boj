#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int N, K;
vector<int> initial;

void input(){
    cin >> N >> K;
    initial.resize(N);
    for(int i = 0; i < N; i++){
        cin >> initial[i];
    }
}

string vecToString(const vector<int>& v){
    string result = "";
    for(int x : v){
        result += to_string(x);
    }
    return result;
}

vector<int> stringToVec(const string& s){
    vector<int> result;
    for(char c : s){
        result.push_back(c - '0');
    }
    return result;
}

void solve(){
    vector<int> target;
    for(int i = 1; i <= N; i++){
        target.push_back(i);
    }
    string targetStr = vecToString(target);
    
    string initialStr = vecToString(initial);
    if(initialStr == targetStr){
        cout << 0 << '\n';
        return;
    }
    
    queue<pair<string, int>> q;
    set<string> visited;
    
    q.push({initialStr, 0});
    visited.insert(initialStr);
    
    while(!q.empty()){
        string current = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        for(int i = 0; i <= N - K; i++){
            vector<int> v = stringToVec(current);
            
            reverse(v.begin() + i, v.begin() + i+ K);
            
            string next = vecToString(v);
            
            if(next == targetStr){
                cout << dist + 1 << '\n';
                return;
            }
            
            if(visited.find(next) == visited.end()){
                visited.insert(next);
                q.push({next, dist + 1});
            }
        }
    }
    
    cout << -1 << '\n';
}

int main(){
    fastio;
    input();
    solve();
    return 0;
}