#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[2000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+N);
    
    long long good = 0;
    
    for(int i = 0 ; i < N ; i++){

        int wantedMake = arr[i];
        
        int l = 0;
        int r = N-1;
        int sum = 0;
        
        while(l < r){
            sum = arr[l] + arr[r];
            
            if(sum == wantedMake){
                if(l != i && r != i){
                    good++;
                    break;
                }
                
                else if(l == i)l++;
                else if(r == i)r--;
            }
            
            else if(sum < wantedMake){
                l++;
            }else{
                r--;
            }
        }
        
    }
    
    cout << good << endl;
   
    return 0;
}
