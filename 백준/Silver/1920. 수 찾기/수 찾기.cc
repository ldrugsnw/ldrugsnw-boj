#include <iostream>
using namespace std;
#include <algorithm>


int n;
int arr[100001];

int binarySearch(int target){
    int start = 0;
    int end = n - 1;
    
    
    while(start <= end){
        int middle = (start + end)/2;
        
        if(arr[middle] == target){
            return 1;
        }
        
        else if(target < arr[middle]){
            end = middle - 1;
        }
        
        else {
            start =middle + 1;
        }
    }
    
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int m;
    cin >> m;
    
    while(m--){
        int t;
        cin >> t;
        cout << binarySearch(t) << '\n';
    }
}
