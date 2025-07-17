#include <iostream>
using namespace std;

int arr[50];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    
    int S; cin >> S;
    
    for(int i = 0; i < N && S > 0; i++){
        int maxVal = arr[i];
        int maxIdx = i;
        
        for(int j = i + 1; j < N && (j - i) <= S; j++){
            if(arr[j] > maxVal){
                maxVal = arr[j];
                maxIdx = j;
            }
        }
        
        while(maxIdx > i && S > 0){
            int tmp = arr[maxIdx];
            arr[maxIdx] = arr[maxIdx-1];
            arr[maxIdx-1] = tmp;
            maxIdx--;
            S--;
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        cout << arr[i] << ' ';
    }
    
    return 0;
}