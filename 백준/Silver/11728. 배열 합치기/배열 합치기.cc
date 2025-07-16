#include <iostream>
#include <algorithm>
using namespace std;

int A[1000001];
int B[1000001];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    int N, M;
    cin >> N >> M;
    
    for(int i = 0 ; i < N ; i++){
        cin >> A[i];
    }

    for(int i = 0 ; i < M ; i++){
        cin >> B[i];
    }
    
    int A_cnt = 0;
    int B_cnt = 0;
    
    
    for(int i = 0 ; i < N + M ; i ++){
        if(A_cnt == N){
            cout << B[B_cnt] << " ";
            B_cnt++;
        }
        
        else if(B_cnt == M){
            cout << A[A_cnt] << " ";
            A_cnt++;
        }
        
        
        else{
            if(A[A_cnt] < B[B_cnt]){ // A의 now가 더 작다
                cout << A[A_cnt] << " ";
                A_cnt++;
            }
            
            else {
                cout << B[B_cnt] << " ";
                B_cnt++;
            }
        }
    }
    
    return 0;
}
