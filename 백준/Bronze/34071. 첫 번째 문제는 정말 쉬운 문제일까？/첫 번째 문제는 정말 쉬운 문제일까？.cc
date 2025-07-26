#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int arr[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    
    int first = 0;
    
    cin >> arr[0];
    first = arr[0];
    
    for(int i = 1 ; i < n ; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    if(first == arr[0]){
        cout << "ez";
    }else if(first == arr[n-1]){
        cout << "hard";
    }else{
        cout << "?";
    }
    
    
    return 0;
    
}
