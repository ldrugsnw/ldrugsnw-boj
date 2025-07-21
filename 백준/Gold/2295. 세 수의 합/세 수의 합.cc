#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int n;
int U[1006];

// a[i] + a[j] + a[k] == a[l];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        int input = 0;
        cin >> input;
        
        U[i] = input;
    }
    
    sort(U, U+n);
    
    vector<int> iANDj;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            iANDj.push_back(U[i] + U[j]);
        }
    }
    
    int result = -1;
    
    sort(iANDj.begin(), iANDj.end());
    
    for(int i = n-1 ; i>0 ; i--){
        for(int j = 0 ; j < i ; j++){
            if(binary_search(iANDj.begin(), iANDj.end(), U[i] - U[j])){
                cout << U[i];
                return 0;
            }
        }
    }
}
