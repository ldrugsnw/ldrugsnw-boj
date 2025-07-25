#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<pair<long long, int>> S;
    int n;
    cin >> n;
    long long result = 0;
    
    for(int i = 0; i < n; i++){
        long long height;
        cin >> height;
        
        int cnt = 1;
        
        while(!S.empty() && S.top().first < height){
            result += S.top().second;
            S.pop();
        }
        
        if(!S.empty() && S.top().first == height){
            result += S.top().second;
            cnt += S.top().second;
            S.pop();
        }
        
        if(!S.empty()){
            result++;
        }
        
        S.push({height, cnt});
    }
    
    cout << result;
    return 0;
}
