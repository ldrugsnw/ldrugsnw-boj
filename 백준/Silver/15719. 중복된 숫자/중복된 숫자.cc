#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10000000];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    int N;
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+N);
    
    int R;
    
    int prev = 0;
    
    for(int i = 0 ; i < N ; i++){
        if(prev == arr[i]){
            R = prev;
            break;
        }
        
        prev = arr[i];
    }
    
    cout << R;
    
    return 0;
}
