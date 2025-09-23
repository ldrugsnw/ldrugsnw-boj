#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int main(){
    fastio;
    
    int N, J, S, H, K;
    
    cin >> N >> J >> S >> H >> K;
    
    string up, mid, down;
    
    cin >> up >> mid >> down;
    
    int leftJump = 0;
    int leftDoubleJump = 0;
    int leftSlide = 0;
    
    
    for(int i = 0 ; i < N ; i++){
        if(up[i] == '.' && mid[i] == '.' && down[i] == '^'){
            leftJump++;
        }
        
        else if(up[i] == '.' && mid[i] == '^' && down[i] == '^'){
            leftDoubleJump++;
        }
        
        else if(up[i] == 'v' && mid[i] == 'v' && down[i] == '.'){
            leftSlide++;
        }
    }
    
    for(int i = 0 ; i < leftJump ; i++){
        if(J>0){
            J--;
        }
        
        else {
            H -= K;
            
            if(H <= 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    for(int i = 0 ; i < leftSlide ; i++){
        if(S>0){ // 슬라이딩 가능
            S--;
        }
        
        else { // 벽에 부딪혀야해
            H -= K;
            
            if(H <= 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    for(int i = 0 ; i < leftDoubleJump ; i++){
        if(J >= 2){
            J -= 2;
        }
        
        else { // 벽에 부딪혀야해
            H -= K;
            
            if(H <= 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    cout << H << endl;
    return 0;
}
