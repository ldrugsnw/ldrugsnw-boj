#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];

int main(){
   
    int N; cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        int count = 0;
        int input = 0;
        cin >> input;
        
        int now = 0;
        
        while(count < input){
            if(arr[now] == 0){
                count++;
                now++;
            }
            
            if(arr[now] != 0){
                now++;
            }
        }
        
        
        while(arr[now] != 0){
            now++;
        }
        
        //cout << "now : " << now << ",    i : " << i << endl;
        arr[now] = i+1;
            
    }
    
    for(int i = 0 ; i < N ; i++){
        cout << arr[i] << ' ';
    }
    
    return 0;
}
