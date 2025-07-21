#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int K; cin >> K; // 영식이가 가지고 있는 랜선의 개수
    int N; cin >> N; // 만들어야하는 랜선의 개수
    
    unsigned int answer = 0;
    
    int list[10000];
    
    int maxi = 0;
    
    for(int i = 0 ; i < K ; i++){
        cin >> list[i];
        maxi = max(maxi, list[i]);
    }
    
    unsigned int left = 1, right = maxi, mid;
    
    while(left <= right){
        mid = (left + right) / 2;
        
        unsigned int now = 0;
        
        for(int i = 0;i < K ;i++){
            now += list[i] / mid;
        }
        
        if(now>=N){
            left = mid + 1;
            
            answer = max(answer, mid);
        }else{
            right = mid - 1;
        }
    }
    
    cout << answer << "\n";
    
    
    return 0;
}
