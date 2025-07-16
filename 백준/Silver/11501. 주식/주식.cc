#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int days[1000001];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    /*아 부자 되고 싶다.*/
    
    int T; cin >> T;
    
    while(T--){
        int len; cin >> len;
        
        for(int i = 0 ; i < len ; i++){
            cin >> days[i];
        }
        
        long long result = 0;
        
        int flag = days[len - 1];
        
        for(int i = len - 2 ; i>=0 ; i--){
            
            if(flag >= days[i]){
                result += (flag - days[i]);
            }
            
            else{
                flag = days[i];
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}
