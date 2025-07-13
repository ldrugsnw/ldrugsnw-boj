#include <iostream>
using namespace std;

int S[10001];

int main(){
    int N, target;
    cin >> N >> target;
    
    int result = 0;
    
    for(int i = 1; i <= N; i++){
        cin >> S[i];
    }
    
    for(int i = 1; i <= N; i++){
        int sum = 0;  
        
        for(int j = i; j <= N; j++){
            sum += S[j];  
            
            if(sum == target){
                result++;
            }
            else if(sum > target){
                break;  
            }
        }
    }
    
    cout << result << "\n";
    
    return 0;
}