#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100007];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    int start = 0;
    int end = N-1;
    int min_abs = 2100000000;
    int save_start, save_end;
    
    while(start < end){
           int sum = arr[start] + arr[end];
           
           if(abs(sum) < min_abs){
               min_abs = abs(sum);
               save_start = start;
               save_end = end;
           }
           
           if(sum < 0){
               start++;
           }
           else if(sum > 0){
               end--;
           }
           else{
               break;
           }
       }
    
    cout << arr[save_start] << " " << arr[save_end];
   
    return 0;
}
