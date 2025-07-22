#include <iostream>
using namespace std;
#include <algorithm>

int arr[100000];
int N, S;
int result = 100000000;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N >> S;
    
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }
    
    int end = 0;
    int total = arr[0];

    
    for(int st = 0 ; st < N ; st++){
        
        while(end < N && total < S){
            end++;
            if(end != N) total += arr[end];
           // cout << "st : " << st << " , end : " << end << endl;
            //cout << "sum_ : " << total << endl;
        }
        
        if(end == N){
            break;
        }
        
        result = min(result, end - st + 1);
        total -= arr[st];

        
       /* cout << "(((((((((((((()))))))))))"<< endl;
        cout << "result :  " << result << endl;
        cout << "(((((((((((((()))))))))))"<< endl;*/

    }
    
    if(result == 100000000)result = 0;
    
    cout << result;
    return 0;
}
