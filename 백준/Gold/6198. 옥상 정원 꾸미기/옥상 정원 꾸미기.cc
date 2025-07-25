#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> S;
    
    int n; cin >> n;
    long long result = 0;
    
    int a; cin >> a;
    
    S.push(a);
    
    //cout << "top : " << S.top() << " , now : " << a << endl;
    
    for(int i = 1 ; i < n ; i++){
        cin >> a;
        //cout << "top : " << S.top() << " , now : " << a << endl;

        while(!S.empty() && S.top() <= a){
            S.pop();
        }
        
        result += S.size();
        S.push(a);
        
        //cout << "result : " << result << endl;
    }
   
    
    cout << result;
    
  
    return 0;
    
}
