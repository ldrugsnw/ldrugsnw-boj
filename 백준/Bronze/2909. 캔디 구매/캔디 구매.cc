#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int main(){
    fastio;
    
    int C, K;
    cin >> C >> K;
    
    int pow = 1;
    
    for(int i = 0 ; i < K ; i++){
        pow *= 10;
    }
    
    int price = 0;
    
    while(price < C){
        price += pow;
    }
    
    int prev = price - pow;
    
    int diff1 = C - prev;
    int diff2 = price - C;
    
    if(diff1 >= diff2){
        cout << price << endl;
    }
    
    else {
        cout << prev << endl;
    }
    
    return 0;
}
