#include <iostream>
#include <cmath>
using namespace std;

#define ll unsigned long long

// n(n+1)/2 <= N 을 만족하는 가장 큰 n을 찾기

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        ll N;
        cin >> N;

        ll left = 0;
        ll right = N;
        ll result = 0;
        
        while(left <= right){
            ll mid = left + (right - left) / 2;
            
            ll triangular = mid * (mid + 1) / 2;
            
            if(triangular <= N){
                result = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        
        cout << result << endl;
        
    }
    
    return 0;
}
