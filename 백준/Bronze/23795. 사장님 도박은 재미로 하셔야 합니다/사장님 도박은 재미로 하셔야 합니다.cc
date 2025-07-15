#include <iostream>
using namespace std;

int main(){
    int res = 0;
    int n; cin >> n;
    
    while(n!=-1){
        res+=n;
        cin >> n;
    }
    
    cout << res;
    return 0;
}
